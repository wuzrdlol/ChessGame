#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "chessBoard.h"

struct chessPiece
{
    sf::Sprite Sprite;
    int pieceID, x, y;
    bool draw = 0;
};

class chessWin
{
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];
    sf::IntRect Holder;
    sf::Color sColors[2];
    sf::Texture pieceTex[12];
    sf::SoundBuffer sBuffer[4];
    sf::Sound sounds[4];
    chessPiece pieces[64];
    chessBoard cBoard;
    int selected[2];
    bool cSelect = 0;
    int sX, sY;

    void FitToHolder();
    void DrawSquares();
    void DrawPieces();
    void MapPieces();
    void MapPieces(move curr);

public:
    chessWin(int width, int height, const char *name, const char *imgPath[12], const char *soundsPath[4]);
    bool Update();
};
#endif