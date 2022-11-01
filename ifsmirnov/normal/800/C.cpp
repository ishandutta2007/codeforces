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

#define div div1

const int maxn = 200500;
vi fs[maxn];

int m;
bool ok[maxn];
int cnt[maxn];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int add(int x, int y, int mod) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}

int mul(i64 x, i64 y, i64 mod) {
    return x*y%mod;
}

void scan() {
    int n;
    cin >> n >> m;
    forn(i, n) {
        int x;
        cin >> x;
        ok[x] = true;
    }
}

int gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int g = gcdex(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return g;
}

int div(int x, int y) {
    int rx, ry;
    int g = gcdex(x, m, rx, ry);
    assert(y%g == 0);
    if (rx < 0) rx += m;
    rx = (i64)rx * (y / g) % m;
    assert((i64)x * rx % m == y);
    return rx;
}

vi nums[maxn];
int d[maxn], anc[maxn];

void solve() {
    forn(i, m) if (!ok[i]) {
        ++cnt[gcd(i, m)];
        nums[gcd(i, m)].pb(i);
    }
    fore(i, 1, m-1) if (m%i == 0) {
        for (int j = i; j <= m; j += i) {
            fs[j].pb(i);
        }
    }

    forn(g, m) if (g) {
        for (int sg: fs[g]) {
            if (d[sg] > d[g]) {
                d[g] = d[sg];
                anc[g] = sg;
            }
        }
        d[g] += cnt[g];
    }

    int g = max_element(d, d+m) - d;
//     cerr << "g: " << g<< endl;
    vi res;
    while (d[g] > 0) {
        res.insert(res.end(), all(nums[g]));
        g = anc[g];
    }
    reverse(all(res));
    if (!ok[0]) res.pb(0);
    cout << res.size() << "\n";
    int last = 1;
    for (int x: res) {
        cout << div(last, x) << " ";
        last = x;
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}