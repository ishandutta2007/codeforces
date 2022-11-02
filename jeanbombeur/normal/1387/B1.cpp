#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_NOEUDS = (100 * 1000);

vector <int> Voisins[MAX_NOEUDS];

int ATraiter[MAX_NOEUDS];
int debut = 0, fin = 0;

int FeuillesAdj[MAX_NOEUDS];
int Degre[MAX_NOEUDS];

int Echange[MAX_NOEUDS];

int distTot = 0;
int nbNoeuds;

void AddLeave(int noeud) {
    for (int dest : Voisins[noeud])
    {
        if (FeuillesAdj[dest] ++ == 0)
        {
            ATraiter[fin ++] = dest;
        }
    }
    return;
}

void Read() {
    scanf("%d", &nbNoeuds);
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
        Degre[a] ++;
        Degre[b] ++;
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (Degre[i] == 1)
        {
            AddLeave(i);
        }
    }
    return;
}

void Delete(int noeud) {
    for (int dest : Voisins[noeud])
    {
        if (Degre[dest] -- == 2)
        {
            AddLeave(dest);
        }
    }
    Degre[noeud] = 0;
    return;
}

void Traite(int noeud) {
    vector <int> Feuilles;
    for (int dest : Voisins[noeud])
    {
        if (Degre[dest] == 1)
        {
            Feuilles.push_back(dest);
        }
    }
    int cur = 0;
    if ((int)Feuilles.size() == 0)
    {
        Delete(noeud);
        return;
    }
    if ((int)Feuilles.size() % 2 == 0)
    {
        Echange[Feuilles[0]] = Feuilles[1];
        Echange[Feuilles[1]] = noeud;
        Echange[noeud] = Feuilles[0];
        cur = 2;
        distTot += 4;
    }
    else
    {
        Echange[Feuilles[0]] = noeud;
        Echange[noeud] = Feuilles[0];
        cur = 1;
        distTot += 2;
    }
    for (int i = cur; i < (int)Feuilles.size(); i += 2)
    {
        Echange[Feuilles[i]] = Feuilles[i + 1];
        Echange[Feuilles[i + 1]] = Feuilles[i];
        distTot += 4;
    }
    Delete(noeud);
    return;
}

void TraiteAll() {
    while (debut < nbNoeuds)
    {
        Traite(ATraiter[debut ++]);
    }
    return;
}

void Solve() {
    TraiteAll();
    printf("%d\n", distTot);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        printf("%d ", Echange[i] + 1);
    }
    printf("\n");
    return;
}

int main() {
    Read();
    Solve();
    return 0;
}