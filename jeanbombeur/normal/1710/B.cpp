#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

pair <int, int> Days[MAX_VALUES];

pair <int, int> Pos[MAX_VALUES];

pair <int, int> TotalRain[3 * MAX_VALUES];
int cnt = 0;

int Ans[MAX_VALUES];

int nbDays, flood;

void Read() {
    scanf("%lld %lld", &nbDays, &flood);
    cnt = 0;
    for (int i = 0; i < nbDays; i ++)
    {
        scanf("%lld %lld", &Days[i].first, &Days[i].second);
        TotalRain[cnt ++] = {Days[i].first - Days[i].second, +1};
        TotalRain[cnt ++] = {Days[i].first, -2};
        TotalRain[cnt ++] = {Days[i].first + Days[i].second, +1};
        Pos[i] = {Days[i].first, i};
    }
    sort(TotalRain, TotalRain + cnt);
    sort(Pos, Pos + nbDays);
    for (int i = 1; i < cnt; i ++)
    {
        TotalRain[i].second += TotalRain[i - 1].second;
    }
    fill_n(Ans, nbDays, 1);
    int bigger = - (1LL << 60);
    int height = 0;
    int cur = 0;
    for (int i = 0; i < nbDays; i ++)
    {
        int id = Pos[i].second;
        int pos = Pos[i].first;
        if (i)
            bigger += Pos[i].first - Pos[i - 1].first;
        while (TotalRain[cur + 1].first < pos)
        {
            height += TotalRain[cur].second * (TotalRain[cur + 1].first - TotalRain[cur].first);
            cur ++;
            if (height > flood)
                bigger = max(bigger, height - flood + pos - TotalRain[cur].first);
        }
        int nvh = height + TotalRain[cur].second * (pos - TotalRain[cur].first);
        if (nvh > flood)
            bigger = max(bigger, nvh - flood);
        if (Days[id].second < bigger)
            Ans[id] = 0;
    }
    bigger = - (1LL << 60);
    height = cur = 0;
    reverse(TotalRain, TotalRain + cnt);
    reverse(Pos, Pos + nbDays);
    for (int i = 0; i < nbDays; i ++)
    {
        int id = Pos[i].second;
        int pos = Pos[i].first;
        if (i)
            bigger += Pos[i - 1].first - Pos[i].first;
        while (TotalRain[cur + 1].first > pos)
        {
            height += TotalRain[cur + 1].second * (TotalRain[cur + 1].first - TotalRain[cur].first);
            cur ++;
            if (height > flood)
                bigger = max(bigger, height - flood + TotalRain[cur].first - pos);
        }
        int nvh = height + TotalRain[cur + 1].second * (pos - TotalRain[cur].first);
        if (nvh > flood)
            bigger = max(bigger, nvh - flood);
        if (Days[id].second < bigger)
            Ans[id] = 0;
    }
    for (int i = 0; i < nbDays; i ++)
    {
        printf("%lld", Ans[i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}