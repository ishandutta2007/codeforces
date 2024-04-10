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
int Ans[MAX_VALUES];

vector <int> Id[MAX_VALUES];

int nbValues;

bool Comp(vector <int> &a, vector <int> &b) {
    return a.size() > b.size();
}

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        Id[i].clear();
    }
    for (int i = 0; i < nbValues; i ++)
    {
        Id[-- Val[i]].push_back(i);
    }
    sort(Id, Id + nbValues, Comp);
    while (Id[0].size())
    {
        int cur = 1;
        int last = Id[0].back();
        while (Id[cur].size())
        {
            Ans[Id[cur].back()] = Val[last];
            last = Id[cur].back();
            Id[cur ++].pop_back();
        }
        Ans[Id[0].back()] = Val[last];
        Id[0].pop_back();
    }
    for (int i = 0; i < nbValues; i ++)
    {
        printf("%lld ", ++ Ans[i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}