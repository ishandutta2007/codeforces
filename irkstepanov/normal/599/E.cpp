#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int n;
vector<vector<int> > G, LCA;
vector<int> pc(1 << 13);

void init()
{
    for (int i = 1; i < (1 << 13); ++i) {
        int j = i;
        while (j) {
            if (j & 1) {
                ++pc[i];
            }
            j >>= 1;
        }
    }
}

int older(int mask)
{
    int ans = -1;
    while (mask) {
        ++ans;
        mask >>= 1;
    }
    return ans;
}

bool bit(int x, int pos)
{
    return (x >> pos) & 1;
}

vector<vector<ll> > dp;

ll solve(int root, int mask)
{
    //cout << root << " " << mask << "\n";
    if (dp[root][mask] != -1) {
        return dp[root][mask];
    }
    if (pc[mask] == 1) {
        dp[root][mask] = 1;
        return 1;
    }
    int old = older(mask);
    if (old == root) {
        old = older(mask - (1 << root));
    }
    ll ans = 0;
    for (int submask = mask - (1 << root); bit(submask, old); submask = (submask - 1) & (mask - (1 << root))) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (bit(submask, i)) {
                v.pb(i);
            }
        }
        int cnt = 0, son = -1;
        for (int i : v) {
            if (G[root][i]) {
                ++cnt;
                son = i;
            }
        }
        if (cnt > 1) {
            continue;
        }
        for (int child : v) {
            if (cnt && son != child) {
                continue;
            }
            bool ok = true;
            for (int x : v) {
                if (LCA[root][x] != -1 && LCA[root][x] != root) {
                    ok = false;
                    break;
                }
                if (x == child) {
                    continue;
                }
                if (G[root][x]) {
                    ok = false;
                    break;
                }
            }
            for (int x : v) {
                if (x == child) {
                    continue;
                }
                if (LCA[x][child] != -1 && LCA[x][child] != child) {
                    ok = false;
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!ok) {
                    break;
                }
                for (int j = 0; j < n; ++j) {
                    if (j == root) {
                        continue;
                    }
                    if (bit(submask, i) && !bit(submask, j) && bit(mask, j)) {
                        if (G[i][j]) {
                            ok = false;
                            break;
                        }
                        if (LCA[i][j] != -1 && LCA[i][j] != root) {
                            ok = false;
                            break;
                        }
                    }
                    if (bit(submask, i) && bit(submask, j)) {
                        if (LCA[i][j] != -1 && !bit(submask, LCA[i][j])) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                //cout << "BEFORE " << root << " " << child << " " << submask << " " << ans << "\n";
                ans += solve(child, submask) * solve(root, mask - submask);
                //cout << "AFTER " << root << " " << child << " " << submask << " " << ans << "\n";
            }
        }
    }
    dp[root][mask] = ans;
    return ans;
}

int main()
{
    init();
    //ifstream cin("input.txt");
    int m, q;
    cin >> n >> m >> q;
    if (!m && !q) {
        ll ans = 1;
        for (int i = 0; i < n - 2; ++i) {
            ans *= (ll) n;
        }
        cout << ans << "\n";
        return 0;
    }
    G.resize(n);
    LCA.resize(n);
    for (int i = 0; i < n; ++i) {
        G[i].assign(n, 0);
        LCA[i].assign(n, -1);
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = G[b][a] = 1;
    }
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;
        if (a == b && a != c) {
            cout << "0\n";
            return 0;
        }
        if (!a && c) {
            cout << "0\n";
            return 0;
        }
        if (!b && c) {
            cout << "0\n";
            return 0;
        }
        if (LCA[a][b] != -1 && LCA[a][b] != c) {
            cout << "0\n";
            return 0;
        }
        LCA[a][b] = LCA[b][a] = c;
    }

    dp.resize(n);
    for (int i = 0; i < n; ++i) {
        dp[i].assign((1 << n), -1);
    }

    cout << solve(0, (1 << n) - 1);

}