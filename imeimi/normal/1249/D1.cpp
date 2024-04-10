#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, k;
vector<pii> R[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        R[l].emplace_back(r, i);
    }
    set<pii> es;
    vector<int> ans;
    for (int i = 1; i <= 200000; ++i) {
        for (pii j : R[i]) es.emplace(j);
        while (!es.empty() && es.begin()->fs < i) {
            es.erase(es.begin());
        }
        while (k < (int)es.size()) {
            ans.push_back(es.rbegin()->se);
            es.erase(prev(es.end()));
        }
    }
    sort(ans.begin(), ans.end());
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    return 0;
}