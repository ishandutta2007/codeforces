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
int sub(int x, int y) { return add(x, mod-y); }
void uub(int &x, int y) { x = sub(x, y); }
int mul(i64 x, i64 y) { return x*y%mod; }

int rev(int x) {
    int k = mod-2;
    int a = 1;
    while (k) {
        if (k%2) a = mul(a, x);
        x = mul(x, x);
        k /= 2;
    }
    return a;
}

const int maxn = 1000500;

bool pr[maxn];
vi prd[maxn];
int sd[maxn]; // smallest

void erath() {
    for (int i = 2; i < maxn; ++i) if (!pr[i]) {
        for (int j = i; j < maxn; j += i) prd[j].pb(i), pr[j] = true;
    }
    for (int i = 2; i < maxn; ++i) sd[i] = prd[i][0];
}

map<pii, int> M;

int repr(int x) {
    const int prs[] = {2,3,5,7,11,13,17};
    int pos = 0;
    int res = 1;
    while (x > 1) {
        int d = sd[x];
        while (x%d == 0) x /= d, res *= prs[pos];
        ++pos;
    }
    return res;
}

int num[1000];
int k;
vi divs[1000];

int id_by_num(int x) {
    int pos = lower_bound(num, num+k, x) - num;
    assert(num[pos] == x);
    return pos;
}

void gensmall() {
    int cnt = 0;
    fore(x, 1, 1000000) if (x == repr(x)) {
        num[k++] = x;
        for (int i = 1; i*i <= x; ++i) if (x%i == 0) {
            divs[k-1].pb(id_by_num(repr(i)));
            if (i*i != x) {
                divs[k-1].pb(id_by_num(repr(x/i)));
            }
        }
        sort(all(divs[k-1]));
        cnt += divs[k-1].size();
    }
//     cout << k << endl;
//     cout << cnt << endl;
}


map<pii, int> MOLD;
int f_old(int r, int n) {
    n = repr(n);
    if (MOLD.count({r, n})) return MOLD[{r, n}];
    int& res = MOLD[{r, n}];
    if (r == 0) return res = 1<<prd[n].size();

    res = 0;
    fore(u, 1, n) if (n%u == 0) udd(res, f_old(r-1, u));
    return res;
}

int f(int r, int n) {
//     n = repr(n);
    if (M.count({r, n})) return M[{r, n}];
    int& res = M[{r, n}];
    if (r == 0) return res = 1<<prd[num[n]].size();

    res = 0;
    for (int i: divs[n]) udd(res, f(r-1, i));
    return res;
}

void solve() {
//     int r = 1;
    forn(i, 15) {
        int x = num[i];
        cout << "[" << i << "] " << x << " -> ";
        int y = x;
        while (y > 1) {
            cout << sd[y] << " ";
            y /= sd[y];
        }
        cout << "\n";
        forn(j, 10) {
            cout << f(j, i);
            if (j) {
                cout << " (" << f(j, i) - f(j-1, i) << ")";
            }
            cout << endl;
        }
    }
}

vi getpoly(int N) {
    int n = 30;
    vector<vi> a(n);
    forn(i, n) {
        a[i].resize(n+1);
        int x = 1;
        forn(j, n) {
            a[i][j] = x;
            x = mul(x, i);
        }
        a[i][n] = f(i, N);
    }

    // gaus
    forn(i, n) {
        int j = i;
        for (int k = i; k < n; ++k) if (a[k][i] != 0) {
            j = k;
            break;
        }
        swap(a[i], a[j]);
        assert(a[i][i] != 0);
        int rv = rev(a[i][i]);
        forn(t, n+1) a[i][t] = mul(a[i][t], rv);
        forn(k, n) if (k != i) {
            int cf = a[k][i];
            forn(t, n+1) uub(a[k][t], mul(a[i][t], cf));
        }
    }

//     forn(i, n) {
//         for (int x: a[i]) cout << x << " ";
//         cout << endl;
//     }
    vi res;
    forn(i, n) res.pb(a[i][n]);
    while (!res.empty() && !res.back()) res.pop_back();
    assert(res.size() < 30);
    return res;
}

vi polys[1000];

int f2(int r, int n) {
    n = id_by_num(repr(n));
    int res = 0;
    int cpow = 1;
    for (int x: polys[n]) {
        udd(res, mul(x, cpow));
        cpow = mul(cpow, r);
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    erath();
//     cerr << "Time elapsed for erath: " << clock() / 1000 << " ms" << endl;

    gensmall();

    forn(i, k) polys[i] = getpoly(i);
//     cerr << "Time elapsed for polys: " << clock() / 1000 << " ms" << endl;

    int t;
    scanf("%d", &t);
    forn(i, t) {
        int r, n;
        scanf("%d%d", &r, &n);

//         printf("%d\n", f_old(r, n));
        printf("%d\n", f2(r, n));
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}