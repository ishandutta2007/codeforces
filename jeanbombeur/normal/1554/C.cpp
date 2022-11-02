#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int n, m;

void Read() {
    scanf("%lld %lld", &n, &m);
    if (n > m)
    {
        printf("0\n");
        return;
    }
    int k = 0;
    while ((1 << k) <= m + 1)
        k ++;
    int ans = 0;
    int sum = 0;
    for (int i = k; i >= 0; i --)
    {
        if (n & (1 << i))
            sum += (1 << i);
        if (!(n & (1 << i)) && sum + (1 << i) - 1 <= m)
        {
            sum += (1 << i);
            ans += (1 << i);
        }
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