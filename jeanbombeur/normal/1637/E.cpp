#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define int long long
using namespace std;

//  <|_|>

// Finally

const int MAX_VALUES = (2e5);

vector <int> BadPairs;
map <int, int> Cnt;

vector <int> Values[MAX_VALUES];

vector <int> UsedCnt;

int nbValues, nbPairs;

void Solve() {
    scanf("%lld %lld", &nbValues, &nbPairs);
    Cnt.clear();
    BadPairs.clear();
    UsedCnt.clear();
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Cnt[a] ++;
        BadPairs.push_back((a << 30) + a);
    }
    for (int i = 0; i < nbPairs; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        BadPairs.push_back((a << 30) + b);
        BadPairs.push_back((b << 30) + a);
    }
    sort(BadPairs.begin(), BadPairs.end());
    for (pair <int, int> a : Cnt)
    {
        Values[a.second].push_back(a.first);
        UsedCnt.push_back(a.second);
    }
    sort(UsedCnt.begin(), UsedCnt.end());
    UsedCnt.resize(unique(UsedCnt.begin(), UsedCnt.end()) - UsedCnt.begin());
    for (int cur : UsedCnt)
    {
        reverse(Values[cur].begin(), Values[cur].end());
    }
    int ans = 0;
    for (int l = 0; l < (int)UsedCnt.size(); l ++)
    {
        int a = UsedCnt[l];
        int szA = Values[a].size();
        for (int k = 0; k <= l; k ++)
        {
            int b = UsedCnt[k];
            int szB = Values[b].size();
            for (int i = 0; i < szA; i ++)
            {
                int j = 0;
                while (j < szB)
                {
                    if (!binary_search(BadPairs.begin(), BadPairs.end(), (Values[a][i] << 30) + Values[b][j]))
                    {
                        ans = max(ans, (a + b) * (Values[a][i] + Values[b][j]));
                        szB = j;
                    }
                    j ++;
                }
            }
        }
    }
    for (int a : UsedCnt)
        Values[a].clear();
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