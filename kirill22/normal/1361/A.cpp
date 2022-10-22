#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    vector<int> used(n, -1);
    for (int i = 0; i < n; i++) {
        unordered_set<int> b;
        for (auto x : g[a[i].se]) if (used[x] != -1) b.insert(used[x]);
        int cnt = 1;
        while (b.find(cnt) != b.end()) cnt++;
        if (cnt != a[i].fi) {
            cout << -1;
            return 0;
        }
        used[a[i].se] = a[i].fi;
    }
    for (int i = 0; i < n; i++) cout << a[i].se + 1 << " ";
}