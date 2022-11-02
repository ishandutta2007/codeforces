#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <random>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

mt19937 rng(69420);

const int MAX_VALUES = (2e5);

bool IsNotPrime[2 * MAX_VALUES + 1];

int Ans[MAX_VALUES];

int nbValues;

int Gcd(int a, int b) {
    return b == 0 ? a : Gcd(b, a % b);
}

int Query(int a, int b) {
    printf("? %lld %lld", a + 1, b + 1);
    cout << endl;
    int ans;
    scanf("%lld", &ans);
    return ans;
}

void InitSieve() {
    for (int i = 2; i <= 2 * MAX_VALUES; i ++)
    {
        if (!IsNotPrime[i])
        {
            for (int j = 2 * i; j <= 2 * MAX_VALUES; j += i)
                IsNotPrime[j] = true;
        }
    }
    return;
}

void Solve() {
    scanf("%lld", &nbValues);
    if (nbValues <= 100)
    {
        fill_n(Ans, nbValues, 0);
        for (int i = 0; i < nbValues; i ++)
        {
            for (int j = i + 1; j < nbValues; j ++)
            {
                int a = Query(i, j);
                Ans[i] = Gcd(Ans[i], a);
                Ans[j] = Gcd(Ans[j], a);
            }
        }
        if (nbValues == 3 && ~(Ans[0] | Ans[1] | Ans[2]) & 1)
        {
            if (Ans[0] == Ans[1] + Ans[2])
                Ans[0] >>= 1;
            else if (Ans[1] == Ans[0] + Ans[2])
                Ans[1] >>= 1;
            else
                Ans[2] >>= 1;
        }
    }
    else
    {
        int champ = -1, value = -1;
        for (int t = 0; t < 500; t ++)
        {
            int a = rng() % nbValues;
            int val = 0;
            for (int u = 0; u < 10; u ++)
            {
                int b = a;
                while (a == b)
                    b = rng() % nbValues;
                val = Gcd(val, Query(a, b));
                if (val <= 2 * MAX_VALUES && !IsNotPrime[val])
                    break;
            }
            if (val <= 2 * MAX_VALUES && val > value && !IsNotPrime[val])
                champ = a, value = val;
        }
        for (int i = 0; i < nbValues; i ++)
        {
            if (i == champ)
                Ans[i] = value;
            else
                Ans[i] = Query(i, champ) / value;
        }
    }
    printf("!");
    for (int i = 0; i < nbValues; i ++)
    {
        printf(" %lld", Ans[i]);
    }
    cout << endl;
    return;
}

signed main() {
    InitSieve();
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}