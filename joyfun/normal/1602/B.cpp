#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
int t;
int n;
vector<int> a(maxn, 0);
typedef pair<int, int> pii;
vector<pii> query[2005];
vector<int> ans(100005, 0);

int main() {
    cin >> t;
    while(t--) {
        for (int i = 0; i <= 12; i++) query[i].clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int q; cin >> q;
        for (int i = 0; i < q;i++) {
            int x, k;
            cin >> x >> k;
            k = min(k, 12);
            query[k].push_back(make_pair(x, i));
        }
        for (int i = 0; i <= 12; i++) {
            for (int j = 0; j < query[i].size(); j++) {
                int x = query[i][j].first;
                int id = query[i][j].second;
                ans[id] = a[x];
            }
            vector<int> cnt(2005, 0);
            for (int i = 1; i <= n; i++) {
                cnt[a[i]]++;
            }
            for (int i = 1; i <= n; i++) a[i] = cnt[a[i]];
        }
        for (int i = 0; i < q; i++) cout << ans[i] << endl;
    }
    return 0;
}