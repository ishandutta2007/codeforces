#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()

const int N = 1501, C = 21;
vector<int> z[N];

struct Q{
    vector<pii> a, b;
    Q() {}
    void add(int x) {
        if (sz(a) == 0) a.pb(x, x);
        else a.pb(x, max(x, a.back().se));
    }
    void del() {
        if (sz(b) == 0) {
            while (sz(a)) {
                auto el = a.back();
                a.pop_back();
                int x = el.fi;
                if (sz(b) == 0) b.pb(x, x);
                else b.pb(x, max(x, b.back().se));
            }
        }
        b.pop_back();
    }
    int get() {
        int res = -1;
        if (sz(a)) res = max(res, a.back().se);
        if (sz(b)) res = max(res, b.back().se);
        return res;
    }
};

Q dp[N * N];

vector<int> g(N), g2(N);
int K = 40, s = 0, n;

void del (int x) {
    x = n - x;
    g[x]--;
    int i = x / K;
    g2[i]--;
    s--;
}

void add (int x) {
    x = n - x;
    g[x]++;
    int i = x / K;
    g2[i]++;
    s++;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        fill(all(g), 0);
        fill(all(g2), 0);
        s = 0;
        for (int j = 0; j < n; j++) {
            bool f = false;
            for (int v = 0; v < sz(z[j]); v++) {
                if (a[i][j] == a[z[j][v]][j]) {
                    z[j][v] = i;
                    while (v + 1 < sz(z[j])) {
                        swap(z[j][v], z[j][v + 1]);
                        v++;
                    }
                    f = true;
                    break;
                }
            }
            if (!f) {
                z[j].pb(i);
                if (z[j].size() >= q + 2) z[j].erase(z[j].begin());
            }
            //debug(z[j]);
        }
        int r = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            for (auto x : z[j]) {
                int c = a[x][j];
                int res = dp[c].get();
                if (res != -1) {
                    del(res);
                }
                dp[c].add(x);
                res = dp[c].get();
                add(res);
            }
            while (true) {
                if (r - j + 1 > i + 1) {
                    for (auto x : z[r]) {
                        int c = a[x][r];
                        int res = dp[c].get();
                        del(res);
                        dp[c].del();
                        res = dp[c].get();
                        if (res != -1) {
                            add(res);
                        }
                    }
                    r--;
                    continue;
                }
                if (s <= q) break;
                //debug(r, A, B);
                int p = 0, tmp = q + 1;
                while (true) {
                    int block = p / K;
                    if (g2[block] < tmp) {
                        tmp -= g2[block];
                        p += K;
                        continue;
                    }
                    while (true) {
                        if (g[p] < tmp) {
                            tmp -= g[p];
                            p++;
                        }
                        else break;
                    }
                    break;
                }
                p = n - p;
                if (i - p + 1 > r - j + 1) break;
                for (auto x : z[r]) {
                    int c = a[x][r];
                    int res = dp[c].get();
                    del(res);
                    dp[c].del();
                    res = dp[c].get();
                    if (res != -1) {
                        add(res);
                    }
                }
                r--;
            }
            //debug(i, j, r);
            ans[r - j + 1]++;
        }
        while (r >= 0) {
            for (auto x : z[r]) {
                int c = a[x][r];
                dp[c].del();
            }
            r--;
        }
    }
    for (int i = n - 1; i >= 1; i--) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}