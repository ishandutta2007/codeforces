#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>

const int MAX_UNIVERSITES = (200 * 1000);

vector <int> Eleves[MAX_UNIVERSITES];

int Universite[MAX_UNIVERSITES];

int Forces[MAX_UNIVERSITES];

int nbUniversites;

void Read() {
    scanf("%lld", &nbUniversites);
    for (int i = 0; i < nbUniversites; i ++)
    {
        Eleves[i].clear();
        Forces[i] = 0;
    }
    for (int i = 0; i < nbUniversites; i ++)
    {
        scanf("%lld", &Universite[i]);
    }
    for (int i = 0; i < nbUniversites; i ++)
    {
        int a;
        scanf("%lld", &a);
        Eleves[-- Universite[i]].push_back(a);
    }
    for (int i = 0; i < nbUniversites; i ++)
    {
        int sz = Eleves[i].size();
        sort(Eleves[i].begin(), Eleves[i].end());
        Eleves[i].push_back(0);
        reverse(Eleves[i].begin(), Eleves[i].end());
        for (int j = 1; j <= sz; j ++)
        {
            Eleves[i][j] += Eleves[i][j - 1];
        }
        for (int j = 1; j <= sz; j ++)
        {
            Forces[j - 1] += Eleves[i][sz - (sz % j)];
        }
    }
    for (int i = 0; i < nbUniversites; i ++)
    {
        printf("%lld ", Forces[i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}