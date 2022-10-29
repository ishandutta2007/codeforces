#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll p[N];
ll x[N];
ll dis[N];
struct range {
    double l, r;
    ll c;
};

struct cmp {
    bool operator()(const range &a, const range &b) const {
        return a.r > b.r;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) cin >> p[i];
    for (ll i = 0; i < m; i++) cin >> x[i];
    sort(x, x + m);
    ll pos = 0;

    vector<range> v;
    for (ll i = 0; i < n; i++) {
        while (pos < m && x[pos] <= 100 * i) pos++;
        dis[i] = 0x3f3f3f3f;
        if (pos != m) dis[i] = min(dis[i], x[pos] - 100 * i);
        if (pos != 0) dis[i] = min(dis[i], 100 * i - x[pos - 1]);
        if (dis[i] == 0) continue;
        v.push_back({100.0 * i - dis[i] + 1e-7, 100.0 * i + dis[i] - 1e-7, p[i]});
    }
    sort(v.begin(), v.end(), [](range a, range b) {
        return a.l < b.l;
    });
    ll ans = 0;
    priority_queue<range, vector<range>, cmp> que;
    ll now = 0;
    for (ll i = 0; i < v.size(); i++) {
        now += v[i].c;
        que.push(v[i]);
        while (!que.empty() && que.top().r < v[i].l) {
            now -= que.top().c;
            que.pop();
        }
        ans = max(now, ans);
    }
    cout << ans << endl;
}