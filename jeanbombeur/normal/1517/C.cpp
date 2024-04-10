#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_LIGNES = 500;
const int NB_DIR = 4;

pair <int, int> Dir[NB_DIR] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int Val[MAX_LIGNES][MAX_LIGNES];

int nbLignes;

bool Valide(int lig, int col) {
    return lig >= 0 && col >= 0 && lig >= col && lig < nbLignes && Val[lig][col] == 0;
}

void Dfs(int lig, int col, int id, int nbLeft) {
    if (nbLeft == 0)
        return;
    for (int i = 0; i < NB_DIR; i ++)
    {
        int nvLig = lig + Dir[i].first;
        int nvCol = col + Dir[i].second;
        if (Valide(nvLig, nvCol))
        {
            Val[nvLig][nvCol] = id;
            Dfs(nvLig, nvCol, id, nbLeft - 1);
            return;
        }
    }
    return;
}

void Read() {
    scanf("%d", &nbLignes);
    for (int i = 0; i < nbLignes; i ++)
    {
        scanf("%d", &Val[i][i]);
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        Dfs(i, i, Val[i][i], Val[i][i] - 1);
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j <= i; j ++)
        {
            printf("%d ", Val[i][j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    Read();
    return 0;
}