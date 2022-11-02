#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

pair <int, int> Val[MAX_VALUES];

pair <int, int> Target[MAX_VALUES];

int nbValues, nbTarget, magic;

pair <int, int> Gcd(int a) {
    int sz = a, nb = 1;
    while (sz % magic == 0)
    {
        sz /= magic, nb *= magic;
    }
    return {sz, nb};
}

void Solve() {
    scanf("%lld %lld", &nbValues, &magic);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i].first);
        Val[i] = Gcd(Val[i].first);
    }
    scanf("%lld", &nbTarget);
    for (int i = 0; i < nbTarget; i ++)
    {
        scanf("%lld", &Target[i].first);
        Target[i] = Gcd(Target[i].first);
    }
    int cur = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        while (cur < nbTarget && Val[i].second > 0)
        {
            if (Target[cur].second == 0)
                cur ++;
            else if (Target[cur].first != Val[i].first)
            {
                printf("No\n");
                return;
            }
            else
            {
                int d = min(Val[i].second, Target[cur].second);
                Val[i].second -= d;
                Target[cur].second -= d;
            }
        }
        if (cur == nbTarget && Val[i].second > 0)
        {
            printf("No\n");
            return;
        }
    }
    if (Target[nbTarget - 1].second > 0)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
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