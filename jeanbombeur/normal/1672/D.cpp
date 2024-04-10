#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (3e5);

int Val[MAX_VALUES];
int Target[MAX_VALUES];

int Count[MAX_VALUES];

vector <int> Id[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        Id[i].clear();
        Count[i] = 1;
    }
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Target[i]);
        Target[i] --;
    }
    for (int i = nbValues - 1; i >= 0; i --)
    {
        Id[-- Val[i]].push_back(i);
    }
    int cur = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        while (cur < nbValues && Val[cur] != Target[i])
        {
            int id = Val[cur];
            Id[id].pop_back();
            if (!Id[id].size())
            {
                printf("NO\n");
                return;
            }
            Count[Id[id].back()] += Count[cur ++];
        }
        if (cur >= nbValues)
        {
            printf("NO\n");
            return;
        }
        if (-- Count[cur] == 0)
        {
            Id[Val[cur]].pop_back();
            cur ++;
        }
    }
    printf("YES\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}