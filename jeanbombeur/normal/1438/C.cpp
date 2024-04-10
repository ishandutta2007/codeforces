#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_LIGNES = (100);

struct arete {
    int lig, col, add;
};

vector <pair <int, int>> alldep = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
vector <pair <int, int>> alladd = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int Val[MAX_LIGNES][MAX_LIGNES];

int Vu[MAX_LIGNES][MAX_LIGNES][2];

vector <arete> Voisins[MAX_LIGNES][MAX_LIGNES][2];

int nbTests;
int nbLignes, nbColonnes;

bool Valide(int lig, int col) {
    return lig >= 0 && lig < nbLignes && col >= 0 && col < nbColonnes;
}

void Take(int lig, int col, int ad) {
    int act = Vu[lig][col][ad];
    for (arete dest : Voisins[lig][col][ad])
    {
        if (Vu[dest.lig][dest.col][dest.add] == 0)
        {
            Vu[dest.lig][dest.col][dest.add] = 3 - act;
            Take(dest.lig, dest.col, dest.add);
        }
    }
    return;
}

void Read() {
    scanf("%d%d", &nbLignes, &nbColonnes);
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            scanf("%d", &Val[i][j]);
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            Voisins[i][j][0].clear();
            Voisins[i][j][1].clear();
            Vu[i][j][0] = 0;
            Vu[i][j][1] = 0;
            for (pair <int, int> dep : alldep)
            {
                int lig = i + dep.first;
                int col = j + dep.second;
                if (Valide(lig, col))
                {
                    for (pair <int, int> ajouts : alladd)
                    {
                        if (Val[i][j] + ajouts.first == Val[lig][col] + ajouts.second)
                        {
                            Voisins[i][j][ajouts.first].push_back({lig, col, ajouts.second});
                        }
                    }
                }
            }
            Voisins[i][j][0].push_back({i, j, 1});
            Voisins[i][j][1].push_back({i, j, 0});
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            for (int k = 0; k < 2; k ++)
            {
                if (Vu[i][j][k] == 0)
                {
                    Vu[i][j][k] = 1;
                    Take(i, j, k);
                }
            }
            if (Vu[i][j][0] == 1)
            {
                printf("%d ", Val[i][j]);
            }
            else
            {
                printf("%d ", Val[i][j] + 1);
            }
        }
        printf("\n");
    }
    return;
}

void Solve() {
    return;
}

int main() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}