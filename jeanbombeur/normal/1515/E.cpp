#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>

const int MAX_ORDIS = (401);

int DP[MAX_ORDIS][MAX_ORDIS];

int InverseFacto[MAX_ORDIS];

int nbOrdis, modulo;

int Expo(int a, int n) {
    if (n == 0)
        return 1;
    int ans = Expo(a, n / 2);
    ans *= ans;
    ans %= modulo;
    if (n & 1)
        ans *= a;
    return ans % modulo;
}

void Init() {
    InverseFacto[0] = 1;
    for (int i = 1; i < MAX_ORDIS; i ++)
    {
        InverseFacto[i] = InverseFacto[i - 1] * Expo(i, modulo - 2);
        InverseFacto[i] %= modulo;
    }
    return;
}

void Read() {
    scanf("%lld%lld", &nbOrdis, &modulo);
    Init();
    for (int i = 1; i <= nbOrdis; i ++)
    {
        DP[i][i] += InverseFacto[i] * Expo(2, i - 1);
        DP[i][i] %= modulo;
        for (int k = 1; k < i; k ++)
        {
            for (int l = 1; l < k; l ++)
            {
                int add = DP[i - l - 1][k - l] * InverseFacto[l];
                add %= modulo;
                DP[i][k] += add * Expo(2, l - 1);
                DP[i][k] %= modulo;
            }
            //printf("%lld ", DP[i][k]);
        }
        //printf("%lld\n", DP[i][i]);
    }
    int ans = 0;
    int facto = 1;
    for (int i = 1; i <= nbOrdis; i ++)
    {
        facto *= i;
        facto %= modulo;
        ans += facto * DP[nbOrdis][i];
        //printf("%lld ", facto * DP[nbOrdis][i] % modulo);
        ans %= modulo;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    Read();
    return 0;
}