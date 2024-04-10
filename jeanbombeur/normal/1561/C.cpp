#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CAVES = (1e5);

pair <int, int> Caves[MAX_CAVES];

int nbCaves;

void Solve() {
    scanf("%lld", &nbCaves);
    for (int i = 0; i < nbCaves; i ++)
    {
        int nb;
        scanf("%lld", &nb);
        int maxi = 0;
        for (int j = 0; j < nb; j ++)
        {
            int a;
            scanf("%lld", &a);
            maxi = max(maxi, a - j + 1);
        }
        Caves[i] = {maxi, nb};
    }
    sort(Caves, Caves + nbCaves);
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < nbCaves; i ++)
    {
        ans += max(0LL, Caves[i].first - cur);
        cur = max(cur, Caves[i].first);
        cur += Caves[i].second;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}