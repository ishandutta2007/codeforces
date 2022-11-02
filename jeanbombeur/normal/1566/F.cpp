#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5 + 1);

pair <int, int> RawSegments[MAX_VALUES];

int Points[MAX_VALUES];

vector <pair <int, int>> Segments[MAX_VALUES];

int DP[MAX_VALUES][2];

int nbPoints, nbSegments;

void Solve() {
    scanf("%lld %lld", &nbPoints, &nbSegments);
    for (int i = 0; i < nbPoints; i ++)
    {
        scanf("%lld", &Points[i]);
    }
    sort(Points, Points + nbPoints);
    Points[nbPoints] = 1LL << 60;
    for (int i = 0; i < nbSegments; i ++)
    {
        scanf("%lld %lld", &RawSegments[i].first, &RawSegments[i].second);
    }
    sort(RawSegments, RawSegments + nbSegments);
    int curPoint = 0;
    for (int i = 0; i < nbSegments; i ++)
    {
        while (RawSegments[i].first > Points[curPoint])
            curPoint ++;
        if (RawSegments[i].second >= Points[curPoint])
            continue;
        while (Segments[curPoint].size() && Segments[curPoint].back().second >= RawSegments[i].second)
            Segments[curPoint].pop_back();
        Segments[curPoint].push_back(RawSegments[i]);
    }
    if ((int)Segments[0].size() == 0)
        DP[0][0] = DP[0][1] = 0;
    else
    {
        DP[0][0] = Points[0] - Segments[0][0].second;
        DP[0][1] = 2 * DP[0][0];
    }
    for (int i = 1; i <= nbPoints; i ++)
    {
        DP[i][0] = DP[i][1] = 1LL << 60;
        int left = Points[i - 1], right = Points[i];
        for (pair <int, int> a : Segments[i])
        {
            right = a.second;
            int transi = min(DP[i - 1][0] + 2 * (left - Points[i - 1]), DP[i - 1][1] + left - Points[i - 1]) + Points[i] - right;
            DP[i][0] = min(DP[i][0], transi);
            DP[i][1] = min(DP[i][1], transi + Points[i] - right);
            left = a.first;
        }
        int transi = min(DP[i - 1][0] + 2 * (left - Points[i - 1]), DP[i - 1][1] + left - Points[i - 1]);
        DP[i][0] = min(DP[i][0], transi);
        DP[i][1] = min(DP[i][1], transi);
    }
    printf("%lld\n", min(DP[nbPoints][0], DP[nbPoints][1]));
    for (int i = 0; i <= nbPoints; i ++)
    {
        Segments[i].clear();
    }
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