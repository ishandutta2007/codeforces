#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

vector<int> solve(int n, int k) {
    if (n <= k * 2) {
        vector<int> res(k, 1);
        n -= k;
        for (int i = 0; i < n; i++) res[i]++;
        return res;
    }
    if (n % 2 == 0) {
        auto res = solve(n / 2, k);
        for (auto& x : res) x *= 2;
        return res;
    }
    if (k % 2 == 1) {
        vector<int> res(k, 1);
        res[0] = res[1] = (n - (k - 2)) / 2;
        return res;
    }
    vector<int> res = solve(n - 1, k - 1);
    res.pb(1);
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    auto res = solve(n, k);
    for (auto x : res) cout << x << " "; cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}