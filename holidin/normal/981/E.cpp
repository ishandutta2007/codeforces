#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;

int dp[N], dp1[N];
bool b[N];

vector <pair<pair<int, int>, int> > v;
vector <int> v1;

int main() {
    int i, j, n, k, q, l, r, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= q; ++i) {
        cin >> l >> r >> x;
        v.push_back({{l, r}, x});
    }
    sort(v.begin(), v.end());
    for (i = 1; i <= n; ++i)
        dp[i] = 0;
    dp[0] = n + 1;
    for (i = 0; i < v.size(); ++i) {
        for (j = 1; j <= n; ++j)
            dp1[j] = 0;
        for (j = 0; j <= n; ++j)
        if (j + v[i].second <= n)
            dp1[j + v[i].second] = min(v[i].first.second, dp[j]);
        for (j = 1;  j<= n; ++j)
            dp[j] = max(dp[j], dp1[j]);
        for (j = 1; j <= n; ++j)
        if (dp[j] >= v[i].first.first)
            b[j] = true;
    }
    for (i = 1; i <= n; ++i)
    if (b[i])
        v1.push_back(i);
    cout << v1.size() << "\n";
    for (i = 0; i < v1.size(); ++i)
        cout << v1[i] << ' ';
}