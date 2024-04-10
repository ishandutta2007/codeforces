#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct query {
    int x1, y1;
    int x2, y2;
};

int n, m;

void print(vector<query> ans, vector<vector<string> > init) {
     for (int i = 0; i < sz(ans); ++i) {
        assert(ans[i].x1 != ans[i].x2 || ans[i].y1 != ans[i].y2);
        assert(!init[ans[i].x1][ans[i].y1].empty());
        char c = init[ans[i].x1][ans[i].y1].back();
        init[ans[i].x1][ans[i].y1].pop_back();
        string tmp = init[ans[i].x2][ans[i].y2];
        init[ans[i].x2][ans[i].y2] = "";
        init[ans[i].x2][ans[i].y2] += c;
        init[ans[i].x2][ans[i].y2] += tmp;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "!" << init[i][j] << "! ";
        }
        cout << "\n";
    }
}

mt19937 rr(1);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    cin >> n >> m;
    vector<vector<string> > a(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<string> > init = a;

    vector<query> ans;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < sz(a[i][m - 1]); ++j) {
            ans.pb({i, m - 1, i, 0});
        }
        a[i][0] = a[i][m - 1] + a[i][0];
        a[i][m - 1] = "";
    }

    for (int j = 0; j + 1 < m; ++j) {
        for (int i = 0; i < sz(a[n - 1][j]); ++i) {
            ans.pb({n - 1, j, 0, j});
        }
        a[0][j] = a[n - 1][j] + a[0][j];
        a[n - 1][j] = "";
    }

    for (int j = sz(a[n - 1][m - 1]) - 1; j >= 0; --j) {
        if (a[n - 1][m - 1][j] == '0') {
            ans.pb({n - 1, m - 1, n - 1, 0});
            a[n - 1][0] += "0";
        } else {
            ans.pb({n - 1, m - 1, 0, m - 1});
            a[0][m - 1] += "1";
        }
    }
    a[n - 1][m - 1] = "";

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            for (int k = sz(a[i][j]) - 1; k >= 0; --k) {
                if (a[i][j][k] == '0') {
                    ans.pb({i, j, n - 1, j});
                    a[n - 1][j] += "0";
                } else {
                    ans.pb({i, j, i, m - 1});
                    a[i][m - 1] += "1";
                }
            }
            a[i][j] = "";
        }
    }

    vector<vector<string> > b(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    int ptri = 0, ptrj = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            for (int k = sz(b[i][j]) - 1; k >= 0; --k) {
                if (b[i][j][k] == '0') {
                    while (a[n - 1][ptrj] == "") {
                        ++ptrj;
                    }
                    if (ptrj != j) {
                        ans.pb({n - 1, ptrj, n - 1, j});
                    }
                    ans.pb({n - 1, j, i, j});
                    a[n - 1][ptrj].pop_back();
                } else {
                    while (a[ptri][m - 1] == "") {
                        ++ptri;
                    }
                    if (ptri != i) {
                        ans.pb({ptri, m - 1, i, m - 1});
                    }
                    ans.pb({i, m - 1, i, j});
                    a[ptri][m - 1].pop_back();
                }
            }
        }
    }

    string res = "";
    for (int j = m - 1; j >= 0; --j) {
        res += b[n - 1][j];
    }
    for (int i = n - 2; i >= 0; --i) {
        res += b[i][m - 1];
    }

    for (int k = sz(res) - 1; k >= 0; --k) {
        if (res[k] == '0') {
            while (a[n - 1][ptrj] == "") {
                ++ptrj;
            }
            ans.pb({n - 1, ptrj, n - 1, m - 1});
            a[n - 1][ptrj].pop_back();
        } else {
            while (a[ptri][m - 1] == "") {
                ++ptri;
            }
            ans.pb({ptri, m - 1, n - 1, m - 1});
            a[ptri][m - 1].pop_back();
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        for (int k = 0; k < sz(b[i][m - 1]); ++k) {
            ans.pb({n - 1, m - 1, i, m - 1});
        }
    }
    for (int j = 0; j + 1 < m; ++j) {
        for (int k = 0; k < sz(b[n - 1][j]); ++k) {
            ans.pb({n - 1, m - 1, n - 1, j});
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].x1 + 1 << " " << ans[i].y1 + 1 << " " << ans[i].x2 + 1 << " " << ans[i].y2 + 1 << "\n";
    }

    /*for (int i = 0; i < sz(ans); ++i) {
        assert(ans[i].x1 != ans[i].x2 || ans[i].y1 != ans[i].y2);
        assert(!init[ans[i].x1][ans[i].y1].empty());
        char c = init[ans[i].x1][ans[i].y1].back();
        init[ans[i].x1][ans[i].y1].pop_back();
        string tmp = init[ans[i].x2][ans[i].y2];
        init[ans[i].x2][ans[i].y2] = "";
        init[ans[i].x2][ans[i].y2] += c;
        init[ans[i].x2][ans[i].y2] += tmp;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            assert(init[i][j] == b[i][j]);
        }
    }*/

    
}