#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (1e5);

pair <int, int> Moves[MAX_VALUES];

int nbMoves, target;

void Read() {
    scanf("%lld %lld", &nbMoves, &target);
    for (int i = 0; i < nbMoves; i ++)
    {
        scanf("%lld %lld", &Moves[i].first, &Moves[i].second);
    }
    sort(Moves + 1, Moves + nbMoves);
    int cur = - (1 << 30);
    int maxi = 0;
    for (int i = 1; i < nbMoves; i ++)
    {
        if (Moves[i].first + Moves[i].second < maxi)
            cur = Moves[i].first;
        else
            maxi = Moves[i].first + Moves[i].second;
    }
    for (int i = 1; i < nbMoves; i ++)
    {
        cur = max(cur, max(Moves[i].first, min(cur, Moves[i].first) + Moves[i].second));
        if (i > 1)
            cur = max(cur, Moves[i - 1].first + Moves[i - 1].second);
        cur = max(cur, Moves[i].first);
    }
    cur = max(Moves[0].first, min(cur, Moves[0].first) + Moves[0].second);
    printf(cur >= target ? "YES\n" : "NO\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}