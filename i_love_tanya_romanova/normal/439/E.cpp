#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <memory.h>


using namespace std;
#define MOD 1000000007LL
#define MAX 100010

long long fakt[MAX],prec[MAX];

long long f_1(int n)
{
    long long p = MOD - 2;
    long long res = 1;
    long long x = n;
    while (p > 0)
    {
        if (p % 2 == 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        p /= 2;
    }
    return res;
}

long long f(int n, int k)
{
    if (n > k)
        return 0;
    long long res = fakt[k-1];
    long long d1 = fakt[k-n];
    long long d2 = fakt[n-1];
    d1 = prec[k-n];
    d2 = prec[n-1];
    res = (res * d1) % MOD;
    res = (res * d2) % MOD;
    return res;
}

long long mas[MAX];

int main()
{
    fakt[0] = 1;
    fakt[1] = 1;
    for (int i = 2; i < MAX; i++)
        fakt[i] = (fakt[i-1] * i)%MOD;
 
 for (int i=0;i<MAX;i++)
  prec[i]=f_1(fakt[i]);
    int Q;
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++)
    {
        int N, K;
        scanf("%d%d", &N, &K);
        vector<int> d;
        vector<int> d2;
        for (int i = 1; i * i <= N; i++)
            if (N % i == 0)
            {
                d.push_back(i);
                if (i < N / i)
                    d2.push_back(N/i);
            }
        if (d2.size() > 0)
            for (int i = d2.size() - 1; i >= 0; i--)
                d.push_back(d2[i]);
        
        for (int i = 0; i < d.size(); i++)
        {
            mas[d[i]] = f(K, d[i]);
        }
        for (int i = 1; i < d.size(); i++)
        {
            mas[d[i]] -= mas[1];
            for (int j = 2; j * j <= d[i]; j++)
                if (d[i] % j == 0)
                {
                    mas[d[i]] = (mas[d[i]] - mas[j] + MOD)%MOD;
                    int z = d[i] / j;
                    if (j < z)
                        mas[d[i]] = (mas[d[i]] - mas[z] + MOD)%MOD;

                }
        }
        cout << mas[N] << "\n";
    }

    return 0;
}