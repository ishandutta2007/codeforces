#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;

int n, s;
int a[mxn];
vector <int> vec;
vector <int> pos[mxn];
vector <vector <int> > dp[mxn][2];
vector <vector <pair <int, int> > > pr[mxn][2];

int dis(int x, int y) {
    x %= n, y %= n;
    return min(abs(x - y), n - abs(x - y));
}

int at(int i, int p) {
    return pos[i][p % pos[i].size()];
}

void write(int x) {
    if (x >= 0) printf("+%d\n", x);
    else printf("%d\n", x);
}

void go(int x, int y) {
    x %= n, y %= n;
    if (abs(x - y) < n - abs(x - y)) write(y - x);
    else write(x < y ? -(x + n - y) : n - x + y);
}

void prt(int i, int c, int l, int r) {
    if (!i) return ;
    if (l == r) {
        prt(i - 1, pr[i][c][l][r].first, pr[i][c][l][r].second, pr[i][c][l][r].second + pos[i - 1].size() - 1);
        int p = at(i - 1, pr[i][c][l][r].first == 0 ? pr[i][c][l][r].second : pr[i][c][l][r].second + pos[i - 1].size() - 1);
        int q = at(i, c == 0 ? l : r);
        go(p, q);
    } else {
        prt(i, pr[i][c][l][r].first, c == 0 ? l + 1 : l, c == 1 ? r - 1 : r);
        int p = at(i, pr[i][c][l][r].first == 0 ? (c == 0 ? l + 1 : l) : (c == 1 ? r - 1 : r));
        int q = at(i, c == 0 ? l : r);
        go(p, q);
    }
}

int main() {
    scanf("%d %d", &n, &s);
    -- s;
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) vec.pb(a[i]);
    vec.pb(-inf);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    rep(i, n) pos[lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin()].pb(i);
    pos[0].pb(s);
    rep(i, vec.size()) {
        rep(c, 2) {
            dp[i][c].resize(pos[i].size() << 1);
            pr[i][c].resize(pos[i].size() << 1);
            rep(j, pos[i].size() << 1) dp[i][c][j].resize(pos[i].size() << 1, inf);
            rep(j, pos[i].size() << 1) pr[i][c][j].resize(pos[i].size() << 1, mp(-1, -1));
        }
    }
    for (int l = 0; l < (pos[0].size() << 1); ++ l)
        for (int r = l; r < (pos[0].size() << 1) && r - l + 1 <= pos[0].size(); ++ r)
            rep(c, 2) dp[0][c][l][r] = 0;
    rep(i, vec.size()) if (i) {
        vector <int> v;
        rep(j, pos[i].size()) v.pb(pos[i][j]);
        rep(j, pos[i].size()) v.pb(pos[i][j] + n);
        rep(j, pos[i - 1].size()) rep(c, 2) {
            int p = at(i - 1, c == 0 ? j : j + pos[i - 1].size() - 1);
            int pre = lower_bound(v.begin(), v.end(), p) - v.begin(); -- pre;
            int suf = pre + 1;
            if (pre >= 0) {
                if (dp[i][0][pre][pre] > dp[i - 1][c][j][j + pos[i - 1].size() - 1] + dis(p, at(i, pre))) {
                    dp[i][0][pre][pre] = dp[i - 1][c][j][j + pos[i - 1].size() - 1] + dis(p, at(i, pre));
                    pr[i][0][pre][pre] = mp(c, j);
                }
            }
            if (suf < v.size()) {
                if (dp[i][0][suf][suf] > dp[i - 1][c][j][j + pos[i - 1].size() - 1] + dis(p, at(i, suf))) {
                    dp[i][0][suf][suf] = dp[i - 1][c][j][j + pos[i - 1].size() - 1] + dis(p, at(i, suf));
                    pr[i][0][suf][suf] = mp(c, j);
                }
            }
        }
        rep(j, pos[i].size()) {
            if (dp[i][0][j + pos[i].size()][j + pos[i].size()] > dp[i][0][j][j]) {
                dp[i][0][j + pos[i].size()][j + pos[i].size()] = dp[i][0][j][j];
                pr[i][0][j + pos[i].size()][j + pos[i].size()] = pr[i][0][j][j];
            }
        }
        rep(j, pos[i].size()) {
            if (dp[i][0][j][j] > dp[i][0][j + pos[i].size()][j + pos[i].size()]) {
                dp[i][0][j][j] = dp[i][0][j + pos[i].size()][j + pos[i].size()];
                pr[i][0][j][j] = pr[i][0][j + pos[i].size()][j + pos[i].size()];
            }
        }
        for (int l = (int)(pos[i].size() << 1) - 1; ~l; -- l) {
            for (int r = l + 1; r < (pos[i].size() << 1) && r - l + 1 <= pos[i].size(); ++ r) {
                rep(c, 2) {
                    int nl = c == 0 ? l + 1 : l;
                    int nr = c == 1 ? r - 1 : r;
                    rep(nc, 2) {
                        if (dp[i][c][l][r] > dp[i][nc][nl][nr] + dis(at(i, nc == 0 ? nl : nr), at(i, c == 0 ? l : r))) {
                            dp[i][c][l][r] = dp[i][nc][nl][nr] + dis(at(i, nc == 0 ? nl : nr), at(i, c == 0 ? l : r));
                            pr[i][c][l][r] = mp(nc, -1);
                        }
                    }
                }
            }
        }
    }
    int ans = inf;
    pair <int, int> ansi = mp(-1, -1);
    rep(i, pos[vec.size() - 1].size()) rep(c, 2) {
        if (ans > dp[vec.size() - 1][c][i][i + pos[vec.size() - 1].size() - 1]) {
            ans = dp[vec.size() - 1][c][i][i + pos[vec.size() - 1].size() - 1];
            ansi = mp(i, c);
        }
    }
    printf("%d\n", ans);
    prt(vec.size() - 1, ansi.second, ansi.first, ansi.first + pos[vec.size() - 1].size() - 1);
    return 0;
}