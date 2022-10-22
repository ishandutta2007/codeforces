#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()

vector<int> comp, X, Y;;
pii a[1000];
int Get[1000][1000];
int dp[1000][1000][4];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    comp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        X.pb(a[i].fi);
        Y.pb(a[i].se);
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            Get[x][y] = 2 * 1e9 + 5;
            if (a[x].fi == a[y].fi) Get[x][y] = min(Get[x][y], abs(a[x].se - a[y].se));
            if (a[x].se == a[y].se) Get[x][y] = min(Get[x][y], abs(a[x].fi - a[y].fi));
        }
    }
    sort(all(X));
    sort(all(Y));
    X.resize(unique(all(X)) - X.begin());
    Y.resize(unique(all(Y)) - Y.begin());
    int N = X.size(), M = Y.size();
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) for (int c = 0; c < 4; c++) dp[i][j][c] = -1;
    unordered_map<int, vector<pii>> st, st2;
    for (int i = 0; i < n; i++) {
        st[a[i].fi].pb({a[i].se, i});
        st2[a[i].se].pb({a[i].fi, i});
    }
    for (auto& el : st) {
        sort(all(el.se));
    }
    for (auto& el : st2) {
        sort(all(el.se));
    }
    for (int i = 0; i < X.size(); i++) {
        int it = 0;
        for (int j = 0; j < Y.size(); j++) {
            int x = X[i], y = Y[j];
            while (it < st[x].size() && st[x][it].fi < y) it++;
            if (it != 0) {
                dp[i][j][0] = st[x][it - 1].se;
            }
            if (it != st[x].size()) {
                dp[i][j][1] = st[x][it].se;
            }
        }
    }
    for (int i = 0; i < Y.size(); i++) {
        int it = 0;
        for (int j = 0; j < X.size(); j++) {
            int x = X[j], y = Y[i];
            while (it < st2[y].size() && st2[y][it].fi < x) it++;
            if (it != 0) {
                dp[j][i][2] = st2[y][it - 1].se;
            }
            if (it != st2[y].size()) {
                dp[j][i][3] = st2[y][it].se;
            }
        }
    }
    auto get2 = [&] (int x2, int y2, int y) {
        int res = 2 * 1e9 + 5;
        if (x2 == a[y].fi) res = min(res, abs(y2 - a[y].se));
        if (y2 == a[y].se) res = min(res, abs(x2 - a[y].fi));
        return res;
    };
    auto check = [&] (int t) {
        fill(all(comp), -1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (comp[i] == -1) {
                queue<int> st;
                st.push(i);
                comp[i] = cnt;
                while (st.size() > 0) {
                    int v = st.front();
                    st.pop();
                    for (int j = 0; j < n; j++) {
                        if (comp[j] == -1) {
                            if (Get[v][j] <= t) {
                                comp[j] = cnt;
                                st.push(j);
                            }
                        }
                    }
                }
                cnt++;
                if (cnt >= 5) return false;
            }
        }
        if (cnt == 1) return true;
        if (cnt == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (comp[i] == comp[j]) continue;
                    if (Get[i][j] <= 2 * t || (abs(a[i].fi - a[j].fi) <= t && abs(a[i].se - a[j].se) <= t)) {
                        return true;
                    }
                }
            }
            return false;
        }
        for (int i = 0; i < X.size(); i++) {
            for (int j = 0; j < Y.size(); j++) {
                int x = X[i], y = Y[j];
                int used = 0;
                for (int c = 0; c < 4; c++) {
                    if (dp[i][j][c] != -1 && get2(x, y, dp[i][j][c]) <= t) used |= (1 << comp[dp[i][j][c]]);
                }
                if (used == (1 << cnt) - 1) return true;
            }
        }
        return false;
    };
    if (check(2e9) == false) {
        cout << -1;
        return 0;
    }
    long long l = -1, r = 2 * 1e9 + 5;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r;
}