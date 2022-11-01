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

const int maxn = 80;
const int mod = 1e9+7;
int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
void udd(int& x, int y) { x = add(x, y); }

int n;
char buf[maxn];
int a[maxn];
int n1[maxn];

const int K = 20;

int d[maxn][1<<K];

void scan() {
    cin >> n >> buf;
    forn(i, n) a[i] = buf[i] - '0';
}

void solve() {
    memset(n1, -1, sizeof n1);
    ford(i, n) {
        if (a[i] == 1) n1[i] = i;
        else n1[i] = n1[i+1];
    }

    int res = 0;
    forn(i, n) {
        d[i][0] = 1;
        forn(mask, 1<<K) if (d[i][mask]) {
            int st = n1[i];
            if (st == -1) continue;
            int x = 0;
            while (st < n) {
                x = x*2 + a[st++];
                if (x > K) break;
                assert(x);
                udd(d[st][mask|(1<<(x-1))], d[i][mask]);
            }
        }
        forn(j, K) udd(res, d[i+1][(1<<j)-1]);
    }

    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}