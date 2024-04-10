#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_LIGNES = 500;
const int NB_DIR = 4;

pair <int, int> Dir[NB_DIR] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int Transi[MAX_LIGNES][MAX_LIGNES][4];

int DistMin[2][MAX_LIGNES][MAX_LIGNES];

int nbLignes, nbColonnes, distTrajet;

bool Valide(int lig, int col) {
    return lig >= 0 && col >= 0 && lig < nbLignes && col < nbColonnes;
}

void Read() {
    scanf("%d%d%d", &nbLignes, &nbColonnes, &distTrajet);
    if (distTrajet % 2 == 1)
    {
        for (int i = 0; i < nbLignes; i ++)
        {
            for (int j = 0; j < nbColonnes; j ++)
            {
                printf("-1 ");
            }
            printf("\n");
        }
        return;
    }
    distTrajet /= 2;
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 1; j < nbColonnes; j ++)
        {
            int d;
            scanf("%d", &d);
            Transi[i][j - 1][3] = d;
            Transi[i][j][1] = d;
        }
    }
    for (int i = 1; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            int d;
            scanf("%d", &d);
            Transi[i - 1][j][2] = d;
            Transi[i][j][0] = d;
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            DistMin[1][i][j] = 0;
        }
    }
    for (int dist = 0; dist < distTrajet; dist ++)
    {
        int prev = (dist + 1) % 2;
        for (int i = 0; i < nbLignes; i ++)
        {
            for (int j = 0; j < nbColonnes; j ++)
            {
                int mini = (1 << 30);
                for (int dir = 0; dir < NB_DIR; dir ++)
                {
                    int nvLig = i + Dir[dir].first;
                    int nvCol = j + Dir[dir].second;
                    if (Valide(nvLig, nvCol))
                    {
                        mini = min(mini, Transi[i][j][dir] + DistMin[prev][nvLig][nvCol]);
                    }
                }
                DistMin[dist % 2][i][j] = mini;
            }
        }
    }
    int cur = (distTrajet - 1) % 2;
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            printf("%d ", 2 * DistMin[cur][i][j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    Read();
    return 0;
}