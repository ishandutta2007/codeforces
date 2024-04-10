#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1e9 + 1;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int> > a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    int l = 0, r = inf;
    while (l != r - 1) {
        int t = (l + r) >> 1;
        bool ok = false;
        vector<vector<char> > p(n, vector<char>(n, false));
        for (int j = 0; j < m; ++j) {
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] >= t) {
                    v.pb(i);
                }
            }
            for (int a = 0; a < sz(v); ++a) {
                for (int b = a + 1; b < sz(v); ++b) {
                    int x = v[a], y = v[b];
                    if (p[x][y] || p[y][x]) {
                        ok = true;
                        break;
                    }
                    p[x][y] = p[y][x] = true;
                }
                if (ok) {
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            l = t;
        } else {
            r = t;
        }
    }

    cout << l << "\n";

}