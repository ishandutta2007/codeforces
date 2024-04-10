#include <iostream>
#include <cstdio>
using namespace std;

//     <|_|>

const int MAX_LIGNES = 300;
char Grille[MAX_LIGNES][MAX_LIGNES];

pair <int, int> Sum[3];

int nbLignes;

void Read() {
    for (int i = 0; i < 3; i ++)
    {
        Sum[i] = {0, 0};
    }
    scanf("%d", &nbLignes);
    for (int i = 0; i < nbLignes; i ++)
    {
        scanf("%s", Grille[i]);
        for (int j = 0; j < nbLignes; j ++)
        {
            if (Grille[i][j] == 'X')
            {
                Sum[(i + j) % 3].first ++;
            }
            if (Grille[i][j] == 'O')
            {
                Sum[(i + j) % 3].second ++;
            }
        }
    }
    pair <int, int> swap = {0, 1};
    for (int i = 0; i < 9; i ++)
    {
        if (i / 3 != i % 3)
        {
            if (Sum[i / 3].first + Sum[i % 3].second < Sum[swap.first].first + Sum[swap.second].second)
            {
                swap = make_pair(i / 3, i % 3);
            }
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbLignes; j ++)
        {
            if (Grille[i][j] == 'X' && (i + j) % 3 == swap.first)
            {
                Grille[i][j] = 'O';
            }
            if (Grille[i][j] == 'O' && (i + j) % 3 == swap.second)
            {
                Grille[i][j] = 'X';
            }
            printf("%c", Grille[i][j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}