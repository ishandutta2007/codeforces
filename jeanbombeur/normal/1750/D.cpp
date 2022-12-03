#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MOD = (998244353);
const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int Erath[MAX_VALUES];

vector <int> Primes;

int nbValues, maximum;

void Init() {
    for (int i = 0; i < MAX_VALUES; i ++)
    {
        Erath[i] = 1;
    }
    for (int i = 2; i < MAX_VALUES; i ++)
    {
        if (Erath[i])
        {
            Primes.push_back(i);
            for (int d = 2 * i; d < MAX_VALUES; d += i)
                Erath[d] = 0;
        }
    }
    return;
}

int Gcd(int a, int b) {
    return b ? Gcd(b, a % b) : a;
}

int Ans(int n, int m) {
    int ans = 0;
    vector <int> cur;
    for (int p : Primes)
    {
        if (n == 1)
            break;
        if (p * p > n)
        {
            cur.push_back(n);
            break;
        }
        if (!(n % p))
        {
            cur.push_back(p);
            while (!(n % p))
                n /= p;
        }
    }
    int nb = cur.size();
    for (int mask = 0; mask < (1 << nb); mask ++)
    {
        int prod = 1;
        int cnt = 0;
        for (int k = 0; k < nb; k ++)
        {
            if ((mask >> k) & 1)
                prod *= cur[k], cnt ^= 1;
        }
        if (cnt)
            ans -= m / prod;
        else
            ans += m / prod;
    }
    return ans;
}

void Read() {
    scanf("%lld %lld", &nbValues, &maximum);
    int ans = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    for (int i = 1; i < nbValues; i ++)
    {
        if (Val[i - 1] % Val[i])
        {
            printf("0\n");
            return;
        }
        ans *= (Ans(Val[i - 1] / Val[i], maximum / Val[i]));
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    Init();
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}