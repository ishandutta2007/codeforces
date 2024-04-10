#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 2050;

int n;
int a[maxn][maxn];
int s[maxn][maxn];
int s0[maxn][maxn];
int b[maxn][maxn];
char buf[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, n) a[i][j] = buf[j]-'0';
    }
}

void rotate() {
    forn(i, n*2) forn(j, n*2) b[i][j] = 1;
    forn(i, n) forn(j, n) {
        b[i+j][i-j+n-1] = a[i][j];
    }
    forn(i, n*2-1) forn(j, n*2-1) a[i][j] = b[i][j];
}

void builds() {
    memset(s, 0, sizeof s);
    memset(s0, 0, sizeof s0);
    forn(i, n) forn(j, n) {
        if (a[i][j] == 0) ++s0[i][j];
        else if (a[i][j] == 2) ++s[i][j];
        else if (a[i][j] == 3) s[i][j] += 10000;

        if (i) s[i][j] += s[i-1][j], s0[i][j] += s0[i-1][j];
        if (j) s[i][j] += s[i][j-1], s0[i][j] += s0[i][j-1];
        if (i&&j) s[i][j] -= s[i-1][j-1], s0[i][j] -= s0[i-1][j-1];
    }
}

int gets(int s[maxn][maxn], int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    int res = s[x2][y2];
    if (x1) res -= s[x1-1][y2];
    if (y1) res -= s[x2][y1-1];
    if (x1&&y1) res += s[x1-1][y1-1];
    return res;
}

ld best = -1;
int b2 = 0, b3 = 0;
#define log2 pizda
ld log2 = logl(2);
ld log3 = logl(3);

bool can(int x, int y, int m) {
    if (gets(s0, x-m, y, x, y)) return false;
    if (gets(s0, x, y-m, x, y)) return false;
    if (gets(s0, x, y, x+m, y)) return false;
    if (gets(s0, x, y, x, y+m)) return false;
    return true;
}

void solve(bool rotated) {
    if (rotated) n = n*2-1;
    builds();
    if (rotated) n = (n+1)/2;

    forn(i, n) forn(j, n) {
        int x, y, bound;
        if (rotated) {
            x = i+j;
            y = j-i+n-1;
            bound = min( min(i, j), min(n-i-1, n-j-1) ) * 2;
        } else {
            x = i;
            y = j;
            bound = min( min(i, j), min(n-i-1, n-j-1) );
        }
        ++bound;

        if (a[x][y] == 0) continue;

        int l = 0, r = bound;
        while (r-l > 1) {
            int m = (l+r)/2;
            if (can(x, y, m)) l = m;
            else r = m;
        }

        int tres = 0;
        tres += gets(s, x-l, y, x-1, y);
        tres += gets(s, x, y-l, x, y-1);
        tres += gets(s, x+1, y, x+l, y);
        tres += gets(s, x, y+1, x, y+l);
        int n2 = tres % 10000;
        int n3 = tres / 10000;
        n2 += a[x][y] == 2;
        n3 += a[x][y] == 3;
        ld score = n2 * log2 + n3 * log3;
        if (score > best) {
            best = score;
            b2 = n2;
            b3 = n3;
        }
    }
}

void solve() {
    solve(false);
    rotate();
    solve(true);

    if (best == -1) cout << 0 << endl;
    else {
        int res = 1;
        forn(i, b2) res = res*2ll % 1000000007;
        forn(i, b3) res = res*3ll % 1000000007;
        cout << res << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}