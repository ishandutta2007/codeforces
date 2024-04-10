#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>

const int MOD = (998244353);
const int MAX_POINTS = (50 * 1000);
const int MAX_VILLES = (20);

int Distances[MAX_POINTS][MAX_VILLES];

int nbVilles, nbPoints;

int Expo(int a, int n) {
    if (n == 1)
        return a;
    int ans = Expo(a, n / 2);
    ans *= ans;
    ans %= MOD;
    if (n & 1)
        ans *= a;
    return ans % MOD;
}

int Inverse(int a) {
    return Expo(a, MOD - 2);
}

void Read() {
    scanf("%lld%lld", &nbVilles, &nbPoints);
    int somme = 0;
    int facto = 1;
    for (int i = 1; i <= nbVilles; i ++)
    {
        facto *= i;
        facto %= MOD;
    }
    for (int i = 0; i < nbVilles; i ++)
    {
        for (int j = 0; j < nbPoints; j ++)
        {
            scanf("%lld", &Distances[j][i]);
        }
    }
    for (int i = 0; i < nbPoints; i ++)
    {
        int esperance = 1;
        sort(Distances[i], Distances[i] + nbVilles);
        for (int j = 0; j < nbVilles; j ++)
        {
            esperance *= Distances[i][j] - j - 1;
            esperance %= MOD;
        }
        somme += facto - esperance + MOD;
    }
    somme %= MOD;
    printf("%lld\n", (somme * Inverse(facto)) % MOD);
    return;
}

signed main() {
    Read();
    return 0;
}