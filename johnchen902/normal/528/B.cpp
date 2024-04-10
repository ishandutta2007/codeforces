#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> vs[200000];
vector<pair<int, int>> dp;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, w;
        scanf("%d %d", &x, &w);
        vs[i] = { x + w, x - w };
    }
    sort(vs, vs + n);
    int ans = 1;
    dp.push_back({vs[0].first, 1});
    for(int i = 1; i < n; i++) {
        auto u = upper_bound(dp.begin(), dp.end(), make_pair(vs[i].second, n));
        if(u == dp.begin()) continue;
        int v = 1 + (--u)->second;
        ans = max(ans, v);
        if(v > dp.back().second)
            dp.push_back({vs[i].first, v});
    }
    printf("%d\n", ans);
}