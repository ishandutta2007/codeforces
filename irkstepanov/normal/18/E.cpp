#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int alpha = 26;
const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > v(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(alpha, vector<int>(alpha)));
    vector<vector<vector<pii> > > pr(n, vector<vector<pii> >(alpha, vector<pii>(alpha)));

    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            if (a == b) {
                continue;
            }
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (j & 1) {
                    if (v[0][j] != b) {
                        ++cnt;
                    }
                } else {
                    if (v[0][j] != a) {
                        ++cnt;
                    }
                }
            }
            dp[0][a - 'a'][b - 'a'] = cnt;
            pr[0][a - 'a'][b - 'a'] = mp(-1, -1);
        }
    }

    for (int i = 1; i < n; ++i) {
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b) {
                    continue;
                }
                int cnt = 0;
                for (int j = 0; j < m; ++j) {
                    if (j & 1) {
                        if (v[i][j] != b) {
                            ++cnt;
                        }
                    } else {
                        if (v[i][j] != a) {
                            ++cnt;
                        }
                    }
                }
                dp[i][a - 'a'][b - 'a'] = inf;
                for (char x = 'a'; x <= 'z'; ++x) {
                    if (x == a) {
                        continue;
                    }
                    for (char y = 'a'; y <= 'z'; ++y) {
                        if (y == b || y == x) {
                            continue;
                        }
                        if (dp[i - 1][x - 'a'][y - 'a'] + cnt < dp[i][a - 'a'][b - 'a']) {
                            dp[i][a - 'a'][b - 'a'] = dp[i - 1][x - 'a'][y - 'a'] + cnt;
                            pr[i][a - 'a'][b - 'a'] = mp(x - 'a', y - 'a');
                        }
                    }
                }
            }
        }
    }

    int ans = inf;
    int x = -1, y = -1;
    for (int a = 0; a < alpha; ++a) {
        for (int b = 0; b < alpha; ++b) {
            if (a == b) {
                continue;
            }
            if (ans > dp[n - 1][a][b]) {
                ans = dp[n - 1][a][b];
                x = a, y = b;
            }
        }
    }

    cout << ans << "\n";

    int pos = n - 1;

    vector<vector<char> > t(n, vector<char>(m));

    while (pos >= 0) {
        for (int j = 0; j < m; ++j) {
            if (j & 1) {
                t[pos][j] = (char)(y + 'a');
            } else {
                t[pos][j] = (char)(x + 'a');
            }
        }
        pii p = pr[pos][x][y];
        --pos;
        x = p.first, y = p.second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << t[i][j];
        }
        cout << "\n";
    }

}