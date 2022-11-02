#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//<|_|>

const int MAX_LIGNES = 200;
const int NB_DEPLACEMENTS = 4;
const int PUIT = 2;
const int SOURCE = 1;

int Deplacements[NB_DEPLACEMENTS][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

struct arete {
    int ligDest, colDest;
    int flot;
};

arete Voisins[MAX_LIGNES][MAX_LIGNES][4];

int Valeur[MAX_LIGNES][MAX_LIGNES];
bool Vu[MAX_LIGNES][MAX_LIGNES];
int Puit[MAX_LIGNES][MAX_LIGNES];

pair <int, pair <int, int>> Bordures[4 * MAX_LIGNES];
int nbBord = 0;

int flotMax = 0;
int nbLignes;

bool Valide(int lig, int col) {
    if (lig < 0 || col < 0 || lig >= nbLignes || col >= nbLignes || Valeur[lig][col] < 0)
    {
        return false;
    }
    return true;
}

void Clear() {
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbLignes; j ++)
        {
            Vu[i][j] = false;
        }
    }
    return;
}

void Read() {
    scanf("%lld", &nbLignes);
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbLignes; j ++)
        {
            scanf("%lld", &Valeur[i][j]);
            if (i % (nbLignes - 1) == 0 || j % (nbLignes - 1) == 0)
            {
                Bordures[nbBord ++] = make_pair(Valeur[i][j], make_pair(i, j));
                Puit[i][j] = SOURCE;
            }
        }
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbLignes; j ++)
        {
            for (int k = 0; k < NB_DEPLACEMENTS; k ++)
            {
                Voisins[i][j][k].ligDest = -1;
                int lig = i + Deplacements[k][0];
                int col = j + Deplacements[k][1];
                if (Valide(lig, col))
                {
                    Voisins[i][j][k] = {lig, col, 0};
                }
            }
        }
    }
    sort(Bordures, Bordures + nbBord);
    return;
}

bool FindPath(int lig, int col) {
    if (Puit[lig][col] == PUIT)
    {
        return true;
    }
    if (Vu[lig][col])
    {
        return false;
    }
    Vu[lig][col] = true;
    for (int i = 0; i < NB_DEPLACEMENTS; i ++)
    {
        arete dest = Voisins[lig][col][i];
        if (dest.ligDest >= 0)
        {
            if (dest.flot == 0)
            {
                if (FindPath(dest.ligDest, dest.colDest))
                {
                    if (Voisins[dest.ligDest][dest.colDest][3 - i].flot == 0)
                    {
                        Voisins[lig][col][i].flot = 1;
                    }
                    Voisins[dest.ligDest][dest.colDest][3 - i].flot = 0;
                    return true;
                }
            }
        }
    }
    return false;
}

bool RemovePath(int lig, int col) {
    if (Puit[lig][col] == PUIT)
    {
        return true;
    }
    for (int i = 0; i < NB_DEPLACEMENTS; i ++)
    {
        arete dest = Voisins[lig][col][i];
        if (dest.ligDest >= 0)
        {
            if (dest.flot == 1)
            {
                Voisins[lig][col][i].flot = 0;
                return RemovePath(dest.ligDest, dest.colDest);
            }
        }
    }
    return false;
}

void Change(int noeud) {
    int lig = Bordures[noeud].second.first;
    int col = Bordures[noeud].second.second;
    for (int i = 0; i < 3; i ++)
    {
        if (RemovePath(lig, col))
        {
            flotMax --;
        }
    }
    Puit[lig][col] = PUIT;
    return;
}

void Solve() {
    int contrasteTotal = 0;
    for (int i = 0; i < nbBord - 1; i ++)
    {
        Change(i);
        Clear();
        for (int j = i + 1; j < nbBord; j ++)
        {
            while (FindPath(Bordures[j].second.first, Bordures[j].second.second))
            {
                flotMax ++;
                Clear();
            }
        }
        contrasteTotal += (flotMax * (Bordures[i + 1].first - Bordures[i].first));
    }
    printf("%lld\n", contrasteTotal);
    return;
}

signed main() {
    Read();
    Solve();
    return 0;
}