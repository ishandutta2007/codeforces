#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
//#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int inf = (int) (1e9 + 5);
const int nmax = (int) (1e3 + 5);

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);

    int n, m;
    scanf("%d%d\n", &n, &m);

    vector<vector<char> > a(n, vector<char>(m));
    forn(i, n) {
        char str[nmax];
        scanf("%s", str);
        forn(j, m) {
            a[i][j] = str[j];
        }
    }

    vector<vector<int> > comp(n, vector<int>(m, -1));
    vector<int> sz;
    int cnt = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    forn(i, n) {
        forn(j, m) {
            if (comp[i][j] != -1) {
                continue;
            }
            if (a[i][j] == '*') {
                continue;
            }
            queue<int> x, y;
            x.push(i), y.push(j);
            comp[i][j] = cnt;
            sz.pb(1);
            while (!x.empty()) {
                int p = x.front(), q = y.front();
                x.pop(), y.pop();
                for (int step = 0; step < 4; ++step) {
                    int pnew = p + dx[step], qnew = q + dy[step];
                    if (pnew >= 0 && pnew < n && qnew >= 0 && qnew < m && a[pnew][qnew] == '.' && comp[pnew][qnew] == -1) {
                        comp[pnew][qnew] = cnt;
                        ++sz.back();
                        x.push(pnew);
                        y.push(qnew);
                    }
                }
            }
            ++cnt;
        }
    }

    forn(i, n) {
        forn(j, m) {
            if (a[i][j] == '.') {
                printf(".");
            } else {
                int ans = 1;
                set<int> s;
                for (int step = 0; step < 4; ++step) {
                    int x = i + dx[step], y = j + dy[step];
                    if (x >= 0 && x < n && y >= 0 && y < m && comp[x][y] != -1) {
                        s.insert(comp[x][y]);
                    }
                }
                for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
                    ans += sz[*it];
                }
                printf("%d", ans % 10);
            }
        }
        printf("\n");
    }

}