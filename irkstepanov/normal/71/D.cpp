#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, m;
vector<vector<string> > a;

bool check(vector<string>& vct) {
    bool suit = true;
    vector<char> ranks;
    for (int i = 0; i < sz(vct); ++i) {
        ranks.pb(vct[i][0]);
        if (vct[i][1] != vct[0][1]) {
            suit = false;
        }
    }
    if (suit) {
        return true;
    }
    sort(all(ranks));
    ranks.resize(unique(all(ranks)) - ranks.begin());
    return sz(ranks) == 9;
}

bool valid(vector<pii>& res) {
    vector<vector<bool> > good(n, vector<bool>(m, false));
    for (int i = 0; i + 3 <= n; ++i) {
        for (int j = 0; j + 3 <= m; ++j) {
            vector<string> vct;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    vct.pb(a[i + x][j + y]);
                }
            }
            if (check(vct)) {
                good[i][j] = true;
            }
        }
    }
    for (int i = 0; i + 3 <= n; ++i) {
        for (int j = 0; j + 3 <= m; ++j) {
            if (!good[i][j]) {
                continue;
            }
            for (int x = i; x <= i + 2 && x + 3 <= n; ++x) {
                for (int y = 0; y + 3 <= m; ++y) {
                    if (y >= j - 2 && y <= j + 2) {
                        continue;
                    }
                    if (good[x][y]) {
                        res = {{i, j}, {x, y}};
                        return true;
                    }
                }
            }
            for (int x = i + 3; x + 3 <= n; ++x) {
                for (int y = 0; y + 3 <= m; ++y) {
                    if (good[x][y]) {
                        res = {{i, j}, {x, y}};
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void print(vector<pii>& ans) {
    cout << "Put the first square to (" << ans[0].first + 1 << ", " << ans[0].second + 1 << ").\n";
    cout << "Put the second square to (" << ans[1].first + 1 << ", " << ans[1].second + 1 << ").\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    cin >> n >> m;

    vector<vector<string> > b(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    vector<char> suits = {'C', 'D', 'H', 'S'};
    vector<char> ranks = {'T', 'J', 'Q', 'K', 'A'};
    for (int i = 2; i < 10; ++i) {
        ranks.pb(char(i + '0'));
    }

    vector<string> rem;
    for (char r : ranks) {
        for (char s : suits) {
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (b[i][j][0] == r && b[i][j][1] == s) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                string curr = "";
                curr += r;
                curr += s;
                rem.pb(curr);
            }
        }
    }

    vector<pii> pos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == "J1" || b[i][j] == "J2") {
                pos.pb({i, j});
            }
        }
    }

    vector<pii> ans;
    if (sz(pos) == 0) {
        a = b;
        bool v = valid(ans);
        if (v) {
            cout << "Solution exists.\n";
            cout << "There are no jokers.\n";
            print(ans);
            return 0;
        } else {
            cout << "No solution.\n";
            return 0;
        }
    }

    if (sz(pos) == 1) {
        a = b;
        for (string s : rem) {
            a[pos[0].first][pos[0].second] = s;
            bool v = valid(ans);
            if (v) {
                cout << "Solution exists.\n";
                cout << "Replace " << b[pos[0].first][pos[0].second] << " with " << s << ".\n";
                print(ans);
                return 0;
            }
        }
        cout << "No solution.\n";
        return 0;
    }

    if (sz(pos) == 2) {
        if (b[pos[0].first][pos[0].second] == "J2") {
            swap(pos[0], pos[1]);
        }
        a = b;
        for (int i = 0; i < sz(rem); ++i) {
            for (int j = 0; j < sz(rem); ++j) {
                if (i == j) {
                    continue;
                }
                a[pos[0].first][pos[0].second] = rem[i];
                a[pos[1].first][pos[1].second] = rem[j];
                bool v = valid(ans);
                if (v) {
                    cout << "Solution exists.\n";
                    cout << "Replace " << b[pos[0].first][pos[0].second] << " with " << rem[i] <<
                            " and " << b[pos[1].first][pos[1].second] << " with " << rem[j] << ".\n";
                    print(ans);
                    return 0;
                }
            }
        }
        cout << "No solution.\n";
        return 0;
    }

}