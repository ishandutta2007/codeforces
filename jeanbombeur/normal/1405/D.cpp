#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_NOEUDS = (100 * 1000);

vector <int> Voisins[MAX_NOEUDS];

int nbTests, nbNoeuds;
int depA, depB, distA, distB;

bool Attrape(int noeud, int pere, int cible, int dist) {
    if (noeud == cible)
    {
        return true;
    }
    if (dist <= 0)
    {
        return false;
    }
    for (int dest : Voisins[noeud])
    {
        if (dest != pere)
        {
            if (Attrape(dest, noeud, cible, dist - 1))
            {
                return true;
            }
        }
    }
    return false;
}

pair <int, int> Parcourt(int noeud, int pere) {
    pair <int, int> maximum = make_pair(0, noeud);
    for (int dest : Voisins[noeud])
    {
        if (dest != pere)
        {
            pair <int, int> nouv = Parcourt(dest, noeud);
            if (++ nouv.first > maximum.first)
            {
                maximum = nouv;
            }
        }
    }
    return maximum;
}

void Solve() {
    if (2 * distA >= distB)
    {
        printf("Alice\n");
        return;
    }
    if (Attrape(depA, depA, depB, distA))
    {
        printf("Alice\n");
        return;
    }
    pair <int, int> nb = Parcourt(0, 0);
    nb = Parcourt(nb.second, nb.second);
    if (nb.first <= 2 * distA)
    {
        printf("Alice\n");
        return;
    }
    printf("Bob\n");
    return;
}

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d%d%d%d%d", &nbNoeuds, &depA, &depB, &distA, &distB);
        depA --;
        depB --;
        for (int j = 0; j < nbNoeuds; j ++)
        {
            Voisins[j].clear();
        }
        for (int j = 1; j < nbNoeuds; j ++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            Voisins[-- a].push_back(-- b);
            Voisins[b].push_back(a);
        }
        Solve();
    }
    return;
}

int main() {
    Read();
    return 0;
}