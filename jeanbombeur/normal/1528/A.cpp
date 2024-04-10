#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

const int MAX_NOEUDS = (200 * 1000);

vector <int> Voisins[MAX_NOEUDS];

pair <int, int> Bornes[MAX_NOEUDS];

int nbNoeuds;

pair <int, int> Dp(int noeud, int pere) {
    pair <int, int> ans = {0, 0};
    for (int dest : Voisins[noeud])
    {
        if (dest != pere)
        {
            pair <int, int> fils = Dp(dest, noeud);
            ans.first += max(abs(Bornes[noeud].first - Bornes[dest].first) + fils.first, abs(Bornes[noeud].first - Bornes[dest].second) + fils.second);
            ans.second += max(abs(Bornes[noeud].second - Bornes[dest].first) + fils.first, abs(Bornes[noeud].second - Bornes[dest].second) + fils.second);
        }
    }
    return ans;
}

void Read() {
    scanf("%lld", &nbNoeuds);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        scanf("%lld%lld", &Bornes[i].first, &Bornes[i].second);
        Voisins[i].clear();
    }
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
    }
    pair <int, int> ans = Dp(0, -1);
    printf("%lld\n", max(ans.first, ans.second));
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}