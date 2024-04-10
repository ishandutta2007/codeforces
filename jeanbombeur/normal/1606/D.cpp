#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

const int MAX_VALUES = (1e6);

vector <int> Val[MAX_VALUES];

pair <int, int> Borders[MAX_VALUES][2];
int Color[MAX_VALUES];

set <pair <int, int>> ChangeMin[2];
set <pair <int, int>> ChangeMax[2];

int nbLines, nbColumns;

void Solve() {
    scanf("%lld %lld", &nbLines, &nbColumns);
    int mini = 0, maxi = 0;
    for (int i = 0; i < nbLines; i ++)
    {
        Val[i].clear();
        for (int j = 0; j < nbColumns; j ++)
        {
            int a;
            scanf("%lld", &a);
            Val[i].push_back(a);
        }
        if (Val[i][0] > Val[maxi][0])
            maxi = i;
        if (Val[i][0] < Val[mini][0])
            mini = i;
    }
    if (Val[mini][0] == Val[maxi][0])
    {
        printf("NO\n");
        return;
    }
    int cut = 0;
    while (cut < nbColumns && Val[mini][cut] < Val[maxi][cut])
        cut ++;
    if (cut == nbColumns)
    {
        printf("NO\n");
        return;
    }
    for (int i = cut; i < nbColumns; i ++)
    {
        if (Val[mini][i] <= Val[maxi][i])
        {
            printf("NO\n");
            return;
        }
    }
    fill_n(Color, nbLines, 2);
    Color[mini] = 0, Color[maxi] = 1;
    ChangeMin[0].clear(), ChangeMin[1].clear();
    ChangeMax[0].clear(), ChangeMax[1].clear();
    for (int i = 0; i < nbLines; i ++)
    {
        int curMini = Val[i][0], curMaxi = Val[i][0];
        for (int j = 0; j < cut; j ++)
        {
            curMini = min(curMini, Val[i][j]);
            curMaxi = max(curMaxi, Val[i][j]);
        }
        Borders[i][0] = {curMini, curMaxi};
        curMini = curMaxi = Val[i][cut];
        for (int j = cut; j < nbColumns; j ++)
        {
            curMini = min(curMini, Val[i][j]);
            curMaxi = max(curMaxi, Val[i][j]);
        }
        Borders[i][1] = {curMini, curMaxi};
        ChangeMin[0].insert({Borders[i][0].first, i});
        ChangeMin[1].insert({Borders[i][1].first, i});
        ChangeMax[0].insert({- Borders[i][0].second, i});
        ChangeMax[1].insert({- Borders[i][1].second, i});
    }
    ChangeMin[0].insert({1e9, -1});
    ChangeMin[1].insert({1e9, -1});
    ChangeMax[0].insert({1e9, -1});
    ChangeMax[1].insert({1e9, -1});
    int maximum[2] = {Borders[mini][0].second, Borders[maxi][1].second};
    int minimum[2] = {Borders[maxi][0].first, Borders[mini][1].first};
    bool t = true;
    while (t)
    {
        t = false;
        for (int i = 0; i < 2; i ++)
        {
            pair <int, int> a = *ChangeMin[i].begin();
            if (a.first <= maximum[i])
            {
                if (Color[a.second] == (1 ^ i))
                {
                    printf("NO\n");
                    return;
                }
                Color[a.second] = i;
                maximum[i] = max(maximum[i], Borders[a.second][i].second);
                minimum[i ^ 1] = min(minimum[i ^ 1], Borders[a.second][i ^ 1].first);
                ChangeMin[i].erase(ChangeMin[i].begin());
                t = true;
            }
            a = *ChangeMax[i].begin();
            if (- a.first >= minimum[i])
            {
                if (Color[a.second] == i)
                {
                    printf("NO\n");
                    return;
                }
                Color[a.second] = 1 ^ i;
                minimum[i] = min(minimum[i], Borders[a.second][i].first);
                maximum[i ^ 1] = max(maximum[i ^ 1], Borders[a.second][i ^ 1].second);
                ChangeMax[i].erase(ChangeMax[i].begin());
                t = true;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < nbLines; i ++)
    {
        // printf("%lld ", Color[i]);
        printf("%c", Color[i] ? 'R' : 'B');
    }
    printf(" %lld\n", cut);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}