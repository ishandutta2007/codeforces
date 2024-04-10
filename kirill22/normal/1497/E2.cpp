#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

const int nx = 2e5 + 1, maxlog = 22;

int dp[nx][maxlog];

vector<int> eratosfen(int n) {
    vector<int> d(n + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > n || x > d[i]) break;
            d[x * i] = x;
        }
    }
    return d;
}

vector<int> d;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.clear();
        while (a[i] > 1) {
            b[d[a[i]]]++;
            a[i] /= d[a[i]];
        }
        for (auto el : b) {
            if (el.se % 2 == 1) a[i] *= el.fi;
        }
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) dp[j][i] = 1e9;
    }
    vector<int> l = {0}, r = {0}, add = {0}, L, R, ADD;
    vector<vector<int>> tmp = {vector<int> (k + 1, 1e9)}, TMP;
    tmp[0][0] = 0;
    unordered_map<int, int> pr;
    dp[0][0]= 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (pr.find(a[i]) != pr.end()) {
            int lv = pr[a[i]];
            L.clear(), R.clear(), ADD.clear(), TMP.clear();
            for (int j = 0; j < sz(l); j++) {
                if (r[j] <= lv) {
                    if (add[j] + 1 <= k) L.pb(l[j]), R.pb(r[j]), ADD.pb(add[j] + 1), TMP.pb(tmp[j]);
                    continue;
                }
                if (l[j] > lv) {
                    L.pb(l[j]), R.pb(r[j]), ADD.pb(add[j]), TMP.pb(tmp[j]);
                    continue;
                }
                if (add[j] + 1 <= k) {
                    L.pb(l[j]), R.pb(lv), ADD.pb(add[j] + 1), TMP.pb(vector<int> (k + 1, 1e9));
                    for (int u = l[j]; u <= lv; u++) {
                        for (int v = 0; v <= k; v++) {
                            TMP[sz(TMP) - 1][v] = min(TMP[sz(TMP) - 1][v], dp[u][v]);
                        }
                    }
                }
                L.pb(lv + 1), R.pb(r[j]), ADD.pb(add[j]), TMP.pb(vector<int> (k + 1, 1e9));
                for (int u = lv + 1; u <= r[j]; u++) {
                    for (int v = 0; v <= k; v++) {
                        TMP[sz(TMP) - 1][v] = min(TMP[sz(TMP) - 1][v], dp[u][v]);
                    }
                }
            }
            l = L, r = R, add = ADD, tmp = TMP;
        }
        for (int j = 0; j < sz(l); j++) {
            for (int v = 0; v + add[j] <= k; v++) {
                dp[i + 1][v + add[j]] = min(dp[i + 1][v + add[j]], tmp[j][v] + 1);
            }
        }
        for (int v = 0; v <= k; v++) dp[i + 1][v] = min(dp[i + 1][v], dp[i][v] + 1);
        if (sz(add) > 0 && add.back() == 0) {
            r[sz(r) - 1]++;
            for (int j = 0; j <= k; j++) tmp[sz(r) - 1][j] = min(tmp[sz(r) - 1][j], dp[i + 1][j]);
        }
        else {
            l.pb(i + 1), r.pb(i + 1), add.pb(0);
            tmp.pb(vector<int> ());
            for (int j = 0; j <= k; j++) tmp[sz(tmp) - 1].pb(dp[i + 1][j]);
        }
        pr[a[i]] = i;
    }
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d = eratosfen(1e7 + 10);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}