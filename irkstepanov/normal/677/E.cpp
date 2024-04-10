#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int inf = 100500;
const ld eps = 1e-8;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    while (a >= mod) {
        a -= mod;
    }
}

int ans2 = 0, ans3 = 0;

void upd(int x, int y)
{
    int a = ans2, b = ans3;
    int ax = min(a, x);
    int by = min(b, y);
    a -= ax, x -= ax;
    b -= by, y -= by;
    ld l = (ld)(a) * log(2.0) + (ld)(b) * log(3.0);
    ld r = (ld)(x) * log(2.0) + (ld)(y) * log(3.0);
    if (lt(l, r)) {
        ans2 = x + ax, ans3 = y + by;
    }
}

int main()
{

    //freopen("input", "r", stdin);
    //ofstream cout("output");

    int n;
    scanf("%d\n", &n);

    vector<vector<char> > m(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c", &m[i][j]);
        }
        scanf("\n");
    }

    vector<vector<vector<int> > > d(8, vector<vector<int> >(n, vector<int>(n)));
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (m[i][j] == '0') {
                    d[k][i][j] = 0;
                    continue;
                }
                if (k == 1 || k == 3 || k == 6 || k == 7) {
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        d[k][i][j] = d[k][x][y] + 1;
                    } else {
                        d[k][i][j] = 1;
                    }
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (m[i][j] == '0') {
                    d[k][i][j] = 0;
                    continue;
                }
                if (k == 2 || k == 4 || k == 0 || k == 5) {
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        d[k][i][j] = d[k][x][y] + 1;
                    } else {
                        d[k][i][j] = 1;
                    }
                }
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 8; ++k) {
                cout << d[k][i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }*/

    vector<vector<vector<int> > > c2(4, vector<vector<int> >(2 * n, vector<int>(n)));
    vector<vector<vector<int> > > c3(4, vector<vector<int> >(2 * n, vector<int>(n)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                if (m[i][j] == '2') {
                    c2[0][i][j] = 1;
                } else if (m[i][j] == '3') {
                    c3[0][i][j] = 1;
                }
            } else {
                c2[0][i][j] = c2[0][i][j - 1];
                c3[0][i][j] = c3[0][i][j - 1];
                if (m[i][j] == '2') {
                    ++c2[0][i][j];
                } else if (m[i][j] == '3') {
                    ++c3[0][i][j];
                }
            }
            if (i == 0) {
                if (m[i][j] == '2') {
                    c2[1][j][i] = 1;
                } else if (m[i][j] == '3') {
                    c3[1][j][i] = 1;
                }
            } else {
                c2[1][j][i] = c2[1][j][i - 1];
                c3[1][j][i] = c3[1][j][i - 1];
                if (m[i][j] == '2') {
                    ++c2[1][j][i];
                } else if (m[i][j] == '3') {
                    ++c3[1][j][i];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (j == 0 || i == n - 1) {
                if (m[i][j] == '2') {
                    c2[2][i + j][j] = 1;
                } else if (m[i][j] == '3') {
                    c3[2][i + j][j] = 1;
                }
            } else {
                c2[2][i + j][j] = c2[2][i + j][j - 1];
                c3[2][i + j][j] = c3[2][i + j][j - 1];
                if (m[i][j] == '2') {
                    ++c2[2][i + j][j];
                } else if (m[i][j] == '3') {
                    ++c3[2][i + j][j];
                }
            }
            if (j == n - 1 || i == n - 1) {
                if (m[i][j] == '2') {
                    c2[3][i - j + n - 1][n - 1 - j] = 1;
                } else if (m[i][j] == '3') {
                    c3[3][i - j + n - 1][n - 1 - j] = 1;
                }
            } else {
                c2[3][i - j + n - 1][n - 1 - j] = c2[3][i - j + n - 1][n - 2 - j];
                c3[3][i - j + n - 1][n - 1 - j] = c3[3][i - j + n - 1][n - 2 - j];
                if (m[i][j] == '2') {
                    ++c2[3][i - j + n - 1][n - 1 - j];
                } else if (m[i][j] == '3') {
                    ++c3[3][i - j + n - 1][n - 1 - j];
                }
            }
        }
    }

    bool zero = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] != '0') {
                zero = false;
                break;
            }
        }
    }
    if (zero) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = inf;
            for (int k = 0; k < 4; ++k) {
                x = min(x, d[k][i][j]);
            }
            int cnt2 = 0, cnt3 = 0;
            cnt2 = c2[0][i][j + x - 1];
            cnt3 = c3[0][i][j + x - 1];
            if (j - x + 1 > 0) {
                cnt2 -= c2[0][i][j - x];
                cnt3 -= c3[0][i][j - x];
            }
            cnt2 += c2[1][j][i + x - 1];
            cnt3 += c3[1][j][i + x - 1];
            if (i - x + 1 > 0) {
                cnt2 -= c2[1][j][i - x];
                cnt3 -= c3[1][j][i - x];
            }
            if (m[i][j] == '2') {
                --cnt2;
            } else if (m[i][j] == '3') {
                --cnt3;
            }
            upd(cnt2, cnt3);
            x = inf;
            for (int k = 4; k < 8; ++k) {
                x = min(x, d[k][i][j]);
            }
            cnt2 = 0, cnt3 = 0;
            cnt2 = c2[2][i + j][j + x - 1];
            cnt3 = c3[2][i + j][j + x - 1];
            if (j - x + 1 > 0) {
                cnt2 -= c2[2][i + j][j - x];
                cnt3 -= c3[2][i + j][j - x];
            }
            cnt2 += c2[3][i - j + n - 1][n - 1 - (j - x + 1)];
            cnt3 += c3[3][i - j + n - 1][n - 1 - (j - x + 1)];
            if (n - 1 - (j + x - 1) > 0) {
                cnt2 -= c2[3][i - j + n - 1][n - 1 - (j + x - 1) - 1];
                cnt3 -= c3[3][i - j + n - 1][n - 1 - (j + x - 1) - 1];
            }
            if (m[i][j] == '2') {
                --cnt2;
            } else if (m[i][j] == '3') {
                --cnt3;
            }
            upd(cnt2, cnt3);
        }
    }

     ll ans = 1;
     while (ans2) {
         mul(ans, 2);
         --ans2;
     }
     while (ans3) {
         mul(ans, 3);
         --ans3;
     }

     cout << ans << "\n";

}