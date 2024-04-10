#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//<|_|>

const int MAX_CARTES = 1200;

int Pere[MAX_CARTES];
int Degre[MAX_CARTES];

int Triples[MAX_CARTES][3];
int nb = 0;

int Joueur[MAX_CARTES];

int PileId[MAX_CARTES];
int Cartes[MAX_CARTES];
int finId = 0, fin = 0;
int cur = 0;

int Feuilles[MAX_CARTES][2];
int finFeuilles[2];

int nbCartes;

void Read() {
    scanf("%d", &nbCartes);
    for (int i = 0; i < 3 * nbCartes; i ++)
    {
        int a;
        scanf("%d", &a);
        Joueur[-- a] ++;
    }
    return;
}

bool IsTriple() {
    if (fin < 3)
    {
        return false;
    }
    if (Joueur[Cartes[fin - 1]] == Joueur[Cartes[fin - 2]] && Joueur[Cartes[fin - 1]] == Joueur[Cartes[fin - 3]])
    {
        return true;
    }
    return false;
}

void CreateStack() {
    for (int i = 0; i < 6 * nbCartes; i ++)
    {
        Cartes[fin ++] = i;
        if (fin >= 2 && Joueur[i] == Joueur[Cartes[fin - 2]])
        {
            if (IsTriple())
            {
                for (int j = 0; j < 3; j ++)
                {
                    Triples[PileId[finId - 1]][j] = Cartes[-- fin];
                }
                if (finId > 1)
                {
                    Pere[PileId[finId - 1]] = PileId[finId - 2];
                    Degre[PileId[finId - 2]] ++;
                }
                else
                {
                    Pere[PileId[finId - 1]] = -1;
                }
                finId --;
            }
        }
        else
        {
            PileId[finId ++] = cur ++;
        }
    }
    return;
}

void Affiche(int a) {
    printf("%d %d %d\n", Triples[a][0] + 1, Triples[a][1] + 1, Triples[a][2] + 1);
    return;
}

void Solve() {
    int nbjokers = 0;
    int joker = -1;
    for (int i = 0; i < 2 * nbCartes; i ++)
    {
        int a = Triples[i][0];
        Triples[i][0] = Triples[i][2];
        Triples[i][2] = a;
        if (Joueur[a] == 0 && Pere[i] < 0)
        {
            nbjokers ++;
        }
    }
    for (int i = 0; i < 2 * nbCartes; i ++)
    {
        if (Degre[i] == 0)
        {
            if (Joueur[Triples[i][0]] == 0 && Pere[i] < 0 && -- nbjokers == 0)
            {
                joker = i;
            }
            else
            {
                Feuilles[finFeuilles[Joueur[Triples[i][0]]] ++][Joueur[Triples[i][0]]] = i;
            }
        }
    }
    for (int i = 0; i < nbCartes; i ++)
    {
        int a = Feuilles[-- finFeuilles[1]][1];
        Affiche(a);
        if (Pere[a] >= 0)
        {
            if (-- Degre[Pere[a]] == 0)
            {
                if (Pere[Pere[a]] < 0 && -- nbjokers == 0)
                {
                    joker = Pere[a];
                }
                else
                {
                    Feuilles[finFeuilles[0] ++][0] = Pere[a];
                }
            }
        }
        if (finFeuilles[0] == 0)
        {
            Affiche(joker);
            return;
        }
        a = Feuilles[-- finFeuilles[0]][0];
        Affiche(a);
        if (Pere[a] >= 0)
        {
            if (-- Degre[Pere[a]] == 0)
            {
                Feuilles[finFeuilles[1] ++][1] = Pere[a];
            }
        }
    }
    printf("%d\n", nbjokers);
    return;
}

void Print() {
    for (int i = 0; i < 6 * nbCartes; i ++)
    {
        printf("%d ", Joueur[i]);
    }
    printf("\n");
    for (int i = 0; i < 2 * nbCartes; i ++)
    {
        printf("%d ", Pere[i]);
    }
    printf("\n");
    for (int i = 0; i < 2 * nbCartes; i ++)
    {
        printf("%d %d %d\n", Triples[i][0], Triples[i][1], Triples[i][2]);
    }
    return;
}

int main() {
    Read();
    CreateStack();
    Solve();
    //Print();
    return 0;
}