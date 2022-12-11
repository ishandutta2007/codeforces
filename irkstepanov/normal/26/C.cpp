#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vector<vector<int> > v(n, vector<int>(m, -1));
    if ((n & 1) && (m & 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int id = 0;

    if ((n & 1) && a < m / 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (n & 1) {
        for (int j = 0; j < m; ++j) {
            v[n - 1][j] = j / 2;
        }
        id = m / 2;
        a -= m / 2;
    }
    if ((m & 1) && b < n / 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (m & 1) {
        for (int i = 0; i < n; ++i) {
            v[i][m - 1] = i / 2;
        }
        id = n / 2;
        b -= n / 2;
    }

    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            if (v[i][j] != -1) {
                continue;
            }
            if (c) {
                v[i][j] = v[i + 1][j] = v[i][j + 1] = v[i + 1][j + 1] = id;
                ++id;
                --c;
            } else if (a >= 2) {
                v[i][j] = v[i][j + 1] = id;
                v[i + 1][j] = v[i + 1][j + 1] = id + 1;
                id += 2;
                a -= 2;
            } else if (b >= 2) {
                v[i][j] = v[i + 1][j] = id;
                v[i][j + 1] = v[i + 1][j + 1] = id + 1;
                id += 2;
                b -= 2;
            } else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }*/

    vector<char> color(id, '?');
    vector<vector<int> > g(id);
    vector<vector<pii> > pos(id);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pos[v[i][j]].pb(mp(i, j));
        }
    }

    for (int i = 0; i < id; ++i) {
        for (int j = i + 1; j < id; ++j) {
            for (pii& x : pos[i]) {
                for (pii& y : pos[j]) {
                    if (abs(x.first - y.first) + abs(x.second - y.second) == 1) {
                        g[i].pb(j);
                        g[j].pb(i);
                    }
                }
            }
        }
    }

    for (int i = 0; i < id; ++i) {
        set<char> bad;
        for (int j : g[i]) {
            bad.insert(color[j]);
        }
        for (char a  = 'a'; ; ++a) {
            if (!bad.count(a)) {
                color[i] = a;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << color[v[i][j]];
        }
        cout << "\n";
    }

}