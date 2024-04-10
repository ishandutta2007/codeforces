#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
mt19937 rnd(58);
const int CS = 1000;
int x[N], y[N], c[N];

vector <pair<pair<int, int>, int> > v[10001];

void solve() {
    int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        v[y[i] / CS].push_back({{x[i], y[i]}, i});
    }
    int f = 0;
    vector <int> ans;
    for (i = 0; i <= N / CS + 1; ++i) {
        sort(v[i].begin(), v[i].end());
        if (i % 2 == 0)
            for (j = 0; j < v[i].size(); ++j)
                ans.push_back(v[i][j].se);
        else
            for (j = (int)v[i].size() - 1; j >= 0; --j)
                ans.push_back(v[i][j].se);
    }
    for (i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << ' ';
        if (i != 0) {
            f += abs(x[ans[i]] - x[ans[i - 1]]) + abs(y[ans[i]] - y[ans[i - 1]]);
        }

    }
    //cout <<f  << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}