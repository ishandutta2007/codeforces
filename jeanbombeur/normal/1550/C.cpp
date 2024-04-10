#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//    We must be better than this

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

pair <int, int> Voisins[MAX_VALEURS];

pair <int, int> Intervalles[2 * MAX_VALEURS];

pair <int, int> Pile[MAX_VALEURS];
int fin = 0;

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    Pile[fin ++] = {-1, -1};
    for (int i = 0; i < nbValeurs; i ++)
    {
        while (fin > 0 && Pile[fin - 1].first > Val[i])
            fin --;
        Voisins[i].first = Pile[fin - 1].second;
        Pile[fin ++] = {Val[i], i};
    }
    fin = 0;
    Pile[fin ++] = {1 << 30, nbValeurs};
    for (int i = nbValeurs - 1; i >= 0; i --)
    {
        while (fin > 0 && Pile[fin - 1].first < Val[i])
            fin --;
        Voisins[i].second = Pile[fin - 1].second;
        Pile[fin ++] = {Val[i], i};
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        Intervalles[i] = {Voisins[i].first, Voisins[i].second};
    }
    fin = 0;
    Pile[fin ++] = {1 << 30, -1};
    for (int i = 0; i < nbValeurs; i ++)
    {
        while (fin > 0 && Pile[fin - 1].first < Val[i])
            fin --;
        Voisins[i].first = Pile[fin - 1].second;
        Pile[fin ++] = {Val[i], i};
    }
    fin = 0;
    Pile[fin ++] = {-1, nbValeurs};
    for (int i = nbValeurs - 1; i >= 0; i --)
    {
        while (fin > 0 && Pile[fin - 1].first > Val[i])
            fin --;
        Voisins[i].second = Pile[fin - 1].second;
        Pile[fin ++] = {Val[i], i};
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        Intervalles[i + nbValeurs] = {Voisins[i].first, Voisins[i].second};
    }
    sort(Intervalles, Intervalles + 2 * nbValeurs);
    int mini = nbValeurs;
    int cur = 2 * nbValeurs - 1;
    for (int i = nbValeurs - 1; i >= 0; i --)
    {
        while (Intervalles[cur].first >= i)
            mini = min(mini, Intervalles[cur --].second);
        ans += mini - i;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}