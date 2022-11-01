#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    typedef pair<int, int> pii;
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pii> v;
    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        v.push_back(pii(t, s));
    }
    sort(v.begin(), v.end());
    const int MOD = (int)(1e9) + 7;
    vector<int> sum(m + 1);
    int ps = 0;
    for (int i = 0; i < m; i++) {
        if (i != 0 && v[i].first != v[i-1].first)
            ps = sum[i];
        int c = lower_bound(v.begin(), v.end(), pii(v[i].second, -1)) - v.begin();
        int q = ps - sum[c];
        if (q < 0)
            q += MOD;
        if (v[i].second == 0)
            ++q;
        if (q >= MOD)
            q %= MOD;
        sum[i+1] = (sum[i] + q) % MOD;
    }
    int res = sum[m];
    res -= sum[lower_bound(v.begin(), v.end(), pii(n, -1)) - v.begin()];
    if (res < 0)
        res += MOD;
    printf("%d\n", res);
    return 0;
}