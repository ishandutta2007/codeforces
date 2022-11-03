#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs, nbCordes;

void Read() {
    scanf("%lld%lld", &nbValeurs, &nbCordes);
    fill_n(Val, 2 * nbValeurs, -1);
    for (int i = 0; i < nbCordes; i ++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        Val[-- a] = -- b;
        Val[b] = a;
    }
    vector <int> Libres;
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        if (Val[i] < 0)
            Libres.push_back(i);
    }
    int sz = Libres.size();
    sz /= 2;
    for (int i = 0; i < sz; i ++)
    {
        Val[Libres[i]] = Libres[i + sz];
        Val[Libres[i + sz]] = Libres[i];
    }
    int ans = 0;
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        for (int j = 0; j < 2 * nbValeurs; j ++)
        {
            if (j != i && j != Val[i])
                ans += (i - j) * (Val[i] - j) * (i - Val[j]) * (Val[i] - Val[j]) < 0;
        }
    }
    printf("%lld\n", ans / 8);
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