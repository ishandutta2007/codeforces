#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MOD = (998244353);
const int MAX_VALUES = (1e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    int ans = 0;
    vector <pair <int, int>> Last;
    for (int i = nbValues - 1; i >= 0; i --)
    {
        vector <pair <int, int>> nv;
        int add = 0;
        for (pair <int, int> a : Last)
        {
            int k = (Val[i] + a.first - 1) / a.first;
            add += (k - 1) * a.second;
            add %= MOD;
            nv.push_back({Val[i] / k, a.second});
        }
        ans += add * (i + 1);
        ans %= MOD;
        nv.push_back({Val[i], 1});
        sort(nv.begin(), nv.end());
        Last.clear();
        for (int j = 0; j < (int)nv.size(); j ++)
        {
            int next = j + 1;
            int sum = nv[j].second;
            while (next < (int)nv.size() && nv[next].first == nv[j].first)
                sum += nv[next ++].second;
            Last.push_back({nv[j].first, sum});
            j = next - 1;
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