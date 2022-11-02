#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

const int MAX_NOEUDS = (100 * 1000);

vector <pair <int, int>> Voisins[MAX_NOEUDS];

int Num[MAX_NOEUDS];
int Ordre[MAX_NOEUDS];

int cur = 0;
int distTot = 0;
int nbNoeuds;

void Read() {
    scanf("%lld", &nbNoeuds);
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        Voisins[-- a].push_back(make_pair(-- b, 0));
        Voisins[b].push_back(make_pair(a, 0));
    }
    return;
}

int NbFils(int noeud, int pere) {
    int sum = 1;
    for (int i = 0; i < (int)Voisins[noeud].size(); i ++)
    {
        if (Voisins[noeud][i].first != pere)
        {
            Voisins[noeud][i].second = NbFils(Voisins[noeud][i].first, noeud);
            sum += Voisins[noeud][i].second;
        }
    }
    for (int i = 0; i < (int)Voisins[noeud].size(); i ++)
    {
        if (Voisins[noeud][i].first == pere)
        {
            Voisins[noeud][i].second = nbNoeuds - sum;
        }
    }
    return sum;
}

int FindCentroide(int noeud) {
    for (pair <int, int> dest : Voisins[noeud])
    {
        if (dest.second > nbNoeuds / 2)
        {
            return FindCentroide(dest.first);
        }
    }
    return noeud;
}

void Ordonne(int noeud, int pere) {
    Num[noeud] = cur;
    Ordre[cur ++] = noeud;
    for (pair <int, int> dest : Voisins[noeud])
    {
        if (dest.first != pere)
        {
            Ordonne(dest.first, noeud);
        }
    }
    return;
}

void Solve() {
    NbFils(0, -1);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        for (pair <int, int> dest : Voisins[i])
        {
            distTot += min(dest.second, nbNoeuds - dest.second);
        }
    }
    int cent = FindCentroide(0);
    Ordonne(cent, -1);
    printf("%lld\n", distTot);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        printf("%lld ", Ordre[(Num[i] + (nbNoeuds / 2)) % nbNoeuds] + 1);
    }
    printf("\n");
    return;
}

signed main() {
    Read();
    Solve();
    return 0;
}