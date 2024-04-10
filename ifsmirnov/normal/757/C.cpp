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

const int mod = 1e9+7;
int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
void udd(int& x, int y) { x = add(x, y); }
int mul(i64 x, i64 y) { return x*y%mod; }

mt19937_64 rr;

const int maxn = 1000600;

int n, m;
u64 rd[maxn*2];
u64 eq[maxn];
int pos[maxn];

int cnt[maxn];

int ff[maxn];

void solve() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        vi a;
        int k;
        scanf("%d", &k);
        forn(j, k) {
            int x;
            scanf("%d", &x);
            --x;
            if (cnt[x] == 0) a.pb(x);
            ++cnt[x];
        }

        for (int x: a) {
            eq[x] += u64(i+1) * rd[pos[x]++];
            eq[x] += u64(cnt[x]+1) * rd[pos[x]++];
            cnt[x] = 0;
        }
    }

    ff[0] = 1;
    forn(i, maxn) if (i) ff[i] = mul(ff[i-1], i);

    int res = 1;
    sort(eq, eq+m);
    int l = 0, r = 0;
    while (l < m) {
        while (eq[l] == eq[r] && r < m) ++r;
        res = mul(res, ff[r-l]);
        l = r;
    }

    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    forn(i, maxn) rd[i] = rr();

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}