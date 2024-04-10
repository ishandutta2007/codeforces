#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

pair <int, int> Persons[MAX_VALUES];

int nbRows, nbColumns, nbPersons;

void Solve() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    nbPersons = nbRows * nbColumns;
    for (int i = 0; i < nbPersons; i ++)
    {
        scanf("%lld", &Persons[i].first);
        Persons[i].second = - i;
    }
    sort(Persons, Persons + nbPersons);
    int ans = 0;
    for (int i = 0; i < nbPersons; i ++)
    {
        for (int j = i + 1; j < nbPersons; j ++)
        {
            ans += Persons[j].second < Persons[i].second;
        }
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}