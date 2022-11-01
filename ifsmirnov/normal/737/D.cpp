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
typedef unsigned u32;

mt19937 rr;

const int inf = 1e9;

typedef tuple<int, int, int, int> t4;

const int sz = 10000000;
u32 ht[sz+100000];
int hval[sz+100000];
int hcnt;
const u32 NONE = -1;

int& get(u32 a, u32 b, u32 c, u32 d) {
    u32 x = 0;
    x = x + a;
    x = x * 4001 + b;
    x = x * 2 + c;
    x = x * 100 + d;

    u32 h = (x >> 17) ^ (x * 10099) ^ ((x * 43) << 5);
    h %= sz;
    while (ht[h] != NONE && ht[h] != x) ++h;

//     assert(h < sz + 10000);
    if (ht[h] == NONE) {
        ht[h] = x;
        hval[h] = inf;
        ++hcnt;
    }
    return hval[h];
}

int n;
int a[5050];
int s[5050];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
//     n = 4000;
//     forn(i, n) a[i] = rr() % 10000;
    forn(i, n) s[i+1] = s[i] + a[i];
}

int go(int l, int r, int par, int k) {
    if (r-l < k) return 0;
    int& res = get(l, r, par, k);
    if (res != inf) return res;

    if (par) res = inf;
    else res = -inf;

    for (int i = k; i <= k+1; ++i) if (r-l >= i) {
        if (par == 0) {
            res = max(res, go(l+i, r, par^1, i) + s[l+i] - s[l]);
        } else {
            res = min(res, go(l, r-i, par^1, i) - s[r] + s[r-i]);
        }
    }

    return res;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    memset(ht, -1, sizeof ht);

    scan();
    cout << go(0, n, 0, 1) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}