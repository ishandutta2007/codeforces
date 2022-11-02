#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

const int MOD = (998244353);
const int MAX_VALEURS = (1000 * 1000 + 1);

int Sigma[MAX_VALEURS];

bool IsPrime[MAX_VALEURS];

int nbPoints;

void SetSigma() {
    for (int i = 0; i < MAX_VALEURS; i ++)
    {
        IsPrime[i] = true;
        Sigma[i] = 1;
    }
    for (int i = 2; i < MAX_VALEURS; i ++)
    {
        if (IsPrime[i])
        {
            for (int k = 1; k * i < MAX_VALEURS; k ++)
            {
                IsPrime[k * i] = false;
                int cur = 2;
                int val = k;
                while (val % i == 0)
                {
                    val /= i;
                    cur ++;
                }
                Sigma[k * i] *= cur;
            }
        }
    }
    return;
}

void Read() {
    scanf("%lld", &nbPoints);
    int sum = 0;
    for (int i = 1; i < nbPoints; i ++)
    {
        sum += sum + Sigma[i];
        while (sum >= MOD)
            sum -= MOD;
    }
    sum += Sigma[nbPoints];
    if (sum >= MOD)
        sum -= MOD;
    printf("%lld\n", sum);
    return;
}

signed main() {
    SetSigma();
    Read();
    return 0;
}