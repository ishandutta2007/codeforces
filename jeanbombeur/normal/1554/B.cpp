#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

pair <int, int> DP[MAX_VALEURS];

int nbValeurs, k;

void ChMax(pair <int, int> &a, int b) {
    if (b > a.first)
    {
        a.second = a.first;
        a.first = b;
    }
    else if (b > a.second && b != a.first)
        a.second = b;
}

void Read() {
    scanf("%lld%lld", &nbValeurs, &k);
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        DP[i] = {-1, -1};
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        ChMax(DP[Val[i]], i + 1);
    }
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        for (int j = 0; (1 << j) <= nbValeurs; j ++)
        {
            if (i & (1 << j))
            {
                ChMax(DP[i], DP[i ^ (1 << j)].first);
                ChMax(DP[i], DP[i ^ (1 << j)].second);
            }
        }
    }
    int ans = - (1LL << 60);
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        // printf("%lld :: %lld %lld\n", i, DP[i].first, DP[i].second);
        if (DP[i].second > 0)
            ans = max(ans, DP[i].first * DP[i].second - k * i);
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