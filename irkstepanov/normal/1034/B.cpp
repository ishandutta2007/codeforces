#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<bool> used;
vector<int> mt;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        int z = m;
        while (z % 6) {
            ++z;
        }
        ll ans = z;
        int cnt = 0;
        while (z != m) {
            --z;
            if (cnt < 3) {
                ans -= 2;
            }
            ++cnt;
        }
        cout << ans << "\n";
        return 0;
    }

    if (n >= 30 || m >= 30) {
        ll ans = n * m;
        if (ans % 2) {
            --ans;
        }
        cout << ans << "\n";
        return 0;
    }

    vector<vector<int> > id(n, vector<int>(m));
    vector<vector<int> > tp(n, vector<int>(m));
    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int z = (i + j) % 2;
            tp[i][j] = z;
            if (z == 0) {
                id[i][j] = cnt0++;
            } else {
                id[i][j] = cnt1++;
            }
        }
    }

    g.resize(cnt0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tp[i][j] != 0) {
                continue;
            }
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    int d = abs(i - x) + abs(j - y);
                    if (d != 3) {
                        continue;
                    }
                    g[id[i][j]].pb(id[x][y]);
                }
            }
        }
    }

    mt.assign(cnt1, -1);
    int ans = 0;

    for (int i = 0; i < cnt0; ++i) {
        used.assign(cnt0, false);
        if (dfs(i)) {
            ans += 2;
        }
    }

    cout << ans << "\n";

}