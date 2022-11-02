#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//     <|_|>

const int MAX_NOEUDS = (200 * 1000);

pair <int, int> Val[MAX_NOEUDS];

int nbNoeuds;

void Read() {
    scanf("%lld", &nbNoeuds);
    int ans = 0;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        scanf("%lld", &Val[i].first);
        Val[i].second = -1;
        ans += Val[i].first;
    }
    for (int i = 1; i < nbNoeuds; i ++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        Val[-- a].second ++;
        Val[-- b].second ++;
    }
    sort(Val, Val + nbNoeuds);
    int cur = nbNoeuds - 1;
    printf("%lld ", ans);
    for (int i = 2; i < nbNoeuds; i ++)
    {
        while (cur > 0 && Val[cur].second == 0)
        {
            cur --;
        }
        Val[cur].second --;
        ans += Val[cur].first;
        printf("%lld ", ans);
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