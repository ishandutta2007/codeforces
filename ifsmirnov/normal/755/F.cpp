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

const int maxn = 1000500;

int n, k;
int p[maxn];
int b[maxn];
map<int, int> cnt;

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", &p[i]), --p[i];
}

int large() {
    int res = 0;
    int k = ::k;
    int add = 0;
    for (auto kv: cnt) {
        int x = kv.fi, y = kv.se;
        add += (x%2) * y;
        x /= 2;
        int can = min(k, x*y);
        res += 2*can;
        k -= can;
    }
    res += min(add, k);
    return res;
}

int d[maxn];
const int inf = 1e9;

int small() {
    forn(i, n+1) d[i] = inf;
    int S = 0;
    d[0] = 0;
    for (auto kv: cnt) {
        int x, y;
        tie(x, y) = kv;
        int NS = S + x*y;
        fore(i, 0, NS) if (d[i] != inf) {
            if (d[i] < y) d[i+x] = min(d[i+x], d[i] + 1);
            d[i] = 0;
        }
        S = NS;
    }
    if (d[k] == 0) return k;
    return k+1;
}

void solve() {
    forn(i, n) if (!b[i]) {
        int j = i, s = 0;
        while (!b[j]) {
            ++s;
            b[j] = 1;
            j = p[j];
        }
        ++cnt[s];
//         cerr << "len " << s << endl;
    }
    /*
    int s = 0;
    fore(i, 1, 100000) {
        s += i;
        if (s >= 1000000) break;
        cnt[i] = 1;
    }
    cerr << "s = " << s << endl;
    */

    int r1 = small();
    int r2 = large();
    cout << r1 << " " << r2 << endl;
}


int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}