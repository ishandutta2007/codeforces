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

const int nmax = 110;

int a[nmax][nmax];
int n, m;

void nx(int& i, int& j) {
    ++j;
    if (j == m) {
        ++i;
        j = 0;
    }
}

char ans[2 * nmax][2 * nmax];

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    memset(a, -1, sizeof(a));
    int b, w, c;
    cin >> b >> w >> c;

    int i = 0, j = 0;
    if ((c - m) % 2) {
        a[0][0] = 4;
        nx(i, j);
        --c;
    }

    while (w--) {
        a[i][j] = 0;
        nx(i, j);
    }

    int val = 2;
    for (int u = j; u < m; ++u) {
        a[i][u] = val;
        val = 7 - val;
    }
    val = 2;
    for (int u = j - 1; u >= 0; --u) {
        a[i + 1][u] = val;
        val = 7 - val;
    }
    c -= m;
    ++i;

    int stj = j;
    while (c && i < n) {
        for (int x = stj; x + 1 < m; x += 2) {
            if (i + 1 < n && c >= 4) {
                a[i][x] = 4;
                a[i][x + 1] = 3;
                a[i + 1][x] = 5;
                a[i + 1][x + 1] = 2;
                c -= 4;
                continue;
            } else {
                break;
            }
        }
        if (i + 1 < n && c >= 2 && a[i][m - 1] == -1) {
            a[i][m - 1] = 4;
            a[i + 1][m - 1] = 5;
            c -= 2;
        }

        for (int x = stj - 2; x >= 0; x -= 2) {
            if (i + 2 < n && c >= 4) {
                a[i + 1][x] = 4;
                a[i + 1][x + 1] = 3;
                a[i + 2][x] = 5;
                a[i + 2][x + 1] = 2;
                c -= 4;
                continue;
            } else {
                break;
            }
        }
        if (i + 2 < n && c >= 2 && a[i + 1][0] == -1) {
            a[i + 1][0] = 3;
            a[i + 2][0] = 2;
            c -= 2;
        }
        i += 2;
    }

    for (int x = 0; x + 1 < m; ++x) {
        if (a[n - 1][x] == -1 && a[n - 1][x + 1] == -1 && c >= 2) {
            a[n - 1][x] = 4;
            a[n - 1][x + 1] = 3;
            c -= 2;
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (a[i][j] == -1) {
                ans[i * 2][j * 2] = '#';
                ans[i * 2 + 1][j * 2] = '#';
                ans[i * 2 + 1][j * 2 + 1] = '#';
                ans[i * 2][j * 2 + 1] = '#';
            } else if (a[i][j] == 0) {
                ans[i * 2][j * 2] = '.';
                ans[i * 2 + 1][j * 2] = '.';
                ans[i * 2 + 1][j * 2 + 1] = '.';
                ans[i * 2][j * 2 + 1] = '.';
            } else if (a[i][j] == 2) {
                ans[i * 2][j * 2] = '.';
                ans[i * 2][j * 2 + 1] = '/';
                ans[i * 2 + 1][j * 2] = '/';
                ans[i * 2 + 1][j * 2 + 1] = '#';
            } else if (a[i][j] == 3) {
                ans[i * 2][j * 2] = '\\';
                ans[i * 2][j * 2 + 1] = '#';
                ans[i * 2 + 1][j * 2] = '.';
                ans[i * 2 + 1][j * 2 + 1] = '\\';
            } else if (a[i][j] == 4) {
                ans[i * 2][j * 2] = '#';
                ans[i * 2][j * 2 + 1] = '/';
                ans[i * 2 + 1][j * 2] = '/';
                ans[i * 2 + 1][j * 2 + 1] = '.';
            } else {
                ans[i * 2][j * 2] = '\\';
                ans[i * 2][j * 2 + 1] = '.';
                ans[i * 2 + 1][j * 2] = '#';
                ans[i * 2 + 1][j * 2 + 1] = '\\';
            }
        }
    }

    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < m * 2; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}