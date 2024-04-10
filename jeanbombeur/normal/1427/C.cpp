#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#define int long long
using namespace std;

//<|_|>

const int INFINI = (1000 * 1000 * 1000);
const int MAX_VALEURS = (100 * 1000 + 1);

pair <int, int> Celeb[MAX_VALEURS];
int Tmps[MAX_VALEURS];

int DP[MAX_VALEURS];

int maximum = - INFINI;

int nbRues, nbCeleb;

void Init() {
    for (int i = 1; i < MAX_VALEURS; i ++)
    {
        DP[i] = - INFINI;
    }
    return;
}

int Dist(int a, int b) {
    int dh = Celeb[a].first - Celeb[b].first;
    int dv = Celeb[a].second - Celeb[b].second;
    return max(dh, - dh) + max(dv, - dv);
}

void Read() {
    scanf("%d%d", &nbRues, &nbCeleb);
    for (int i = 1; i <= nbCeleb; i ++)
    {
        scanf("%d%d%d", &Tmps[i], &Celeb[i].first, &Celeb[i].second);
        Celeb[i].first --;
        Celeb[i].second --;
    }
    return;
}

void Treat(int noeud) {
    for (int i = noeud - 1; i >= 0; i --)
    {
        if (Tmps[noeud] - Tmps[i] > 2 * nbRues)
        {
            DP[noeud] = max(DP[noeud], maximum + 1);
            return;
        }
        if (Tmps[noeud] - Tmps[i] >= Dist(noeud, i))
        {
            DP[noeud] = max(DP[noeud], DP[i] + 1);
        }
    }
    return;
}

void Solve() {
    int act = 0;
    for (int i = 1; i <= nbCeleb; i ++)
    {
        while (Tmps[act] + 2 * nbRues < Tmps[i])
        {
            maximum = max(maximum, DP[act ++]);
        }
        Treat(i);
    }
    while (act <= nbCeleb)
    {
        maximum = max(maximum, DP[act ++]);
    }
    printf("%d\n", maximum);
    return;
}

int main() {
    Init();
    Read();
    Solve();
    return 0;
}