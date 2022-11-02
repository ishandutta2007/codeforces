#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (300);

pair <int, int> Persons[MAX_VALUES * MAX_VALUES];

pair <int, int> Rows[MAX_VALUES];

int nbRows, nbColumns, nbPersons;

void Solve() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    nbPersons = nbRows * nbColumns;
    for (int i = 0; i < nbPersons; i ++)
    {
        scanf("%lld", &Persons[i].first);
        Persons[i].second = i;
    }
    sort(Persons, Persons + nbPersons);
    int ans = 0;
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            Rows[j] = Persons[nbColumns * i + j];
            Rows[j].second *= -1;
        }
        sort(Rows, Rows + nbColumns);
        for (int j = 0; j < nbColumns; j ++)
        {
            for (int k = j + 1; k < nbColumns; k ++)
            {
                ans += Rows[k].second < Rows[j].second;
            }
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