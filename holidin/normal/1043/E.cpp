#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long mod = 1e9 + 9;
const int N = 3e5 + 1;
long long x[N], y[N], ans[N], xpr[N], ypr[N];
vector <pair<int, int> > v;

int main() {
    int i, j, k, n, l, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        v.push_back({x[i] - y[i], i});
    }
    sort(v.begin(), v.end());
    xpr[0] = 0;
    ypr[0] = 0;
    for (i = 0; i < v.size(); ++i) {
        xpr[i + 1] = xpr[i] + x[v[i].se];
        ypr[i + 1] = ypr[i] + y[v[i].se];
    }
    for (i = 0; i < v.size(); ++i) {
        ans[v[i].se] += x[v[i].se] * (v.size() - i - 1) + y[v[i].se] * i + xpr[i] + ypr[v.size()] - ypr[i + 1];
    }
    for (i = 0; i < k; ++i) {
        cin >> a >> b;
        ans[a] -= min(x[a] + y[b], x[b] + y[a]);
        ans[b] -= min(x[a] + y[b], x[b] + y[a]);
    }
    for (i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}