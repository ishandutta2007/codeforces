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
int mul(i64 x, i64 y) { return x*y%mod; }
int sub(int x, int y) { return add(x, mod-y); }
void uub(int &x, int y) { x = sub(x, y); }
void udd(int &x, int y) { x = add(x, y); }

const int K = 9;

int mpow(int x, int k) {
    int a = 1;
    while (k) {
        if (k&1) a = mul(a, x);
        x = mul(x, x);
        k /= 2;
    }
    return a;
}

#define div div1
int div(int x, int y) {
    return mul(x, mpow(y, mod-2));
}

const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int N;
int n;
int dig(int x, int i) {
    return x / p10[i] % 10;
}
int put(int x, int i, int val) {
    return (x / p10[i+1] * p10[i+1]) + val * p10[i] + x % p10[i];
}

bool ok(int x) {
    return true;
    forn(i, N) if (dig(x, i) > K) return false;
    return true;
}

void conv(int *x) {
    forn(pos, N) {
        ford(i, p10[N]) if (ok(i)) {
            int d = dig(i, pos);
            int j = put(i, pos, d-1);
            if (d) {
                udd(x[j], x[i]);
            }
        }
    }
}

void conv_rev(int *x) {
    forn(pos, N) {
        forn(i, p10[N]) if (ok(i)) {
            int d = dig(i, pos);
            int j = put(i, pos, d-1);
            if (d) {
//                 cerr << x[j] << " ";
                uub(x[j], x[i]);
            }
        }
    }
    cerr << endl;
}

const int maxn = 1000500;


int f(vi a) {
    int res = p10[N] - 1;
    for (int x: a) forn(i, N) {
        int d = dig(x, i);
        res = put(res, i, min(d, dig(res, i)));
    }
    return res;
}

vi in;
void scan() {
    int n;
    scanf("%d", &n);
    in.reserve(n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        in.pb(x);
    }
}

int MAX() {
    int res = 0;
    forn(i, N) res += K * p10[i];
    return res;
}

int cnt[maxn];
int sum[maxn];
int sum2[maxn];

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    N = 6;
    n = p10[N];

//     vi res;
    /*
    map<int, int> ans;
    forn(mask, 1<<in.size()) if (mask) {
        vi t;
        forn(i, in.size()) if (mask&(1<<i)) t.pb(in[i]);
        int x = f(t);
        int val = 0;
        forn(i, in.size()) if (mask&(1<<i)) {
            val = add(val, in[i]);
//             val = add(val, in[i]);
        }
        udd(ans[x], mul(val, val));
//         udd(ans[x], val);
    }
    for (auto kv: ans) cerr << kv.fi << ": " << kv.se << endl;
    */

    for (int x: in) {
        ++cnt[x];
        udd(sum[x], x);
        udd(sum2[x], mul(x, x));
    }

    conv(sum);
    conv(sum2);

    conv(cnt);

    forn(i, n) {
        int x = 0;
        udd(x, mul(sum2[i], mpow(2, sub(cnt[i], 1))));
        udd(x, mul(sub(mul(sum[i], sum[i]), sum2[i]), mpow(2, sub(cnt[i], 2))));
        cnt[i] = x;
    }
    conv_rev(cnt);
    i64 res = 0;
//     cerr << n << endl;
    forn(i, n) if (cnt[i]) {
        res ^= (i64)i * cnt[i];
//         cerr << i << ": " << cnt[i] << " " << 1ll * i * cnt[i] << endl;
    }
    cout << res << endl;
//     forn(i, n) if (ok(i)) cout << i << ": " << a[i] << endl;

//     a[1] = 1;
// //     a[10] = 1;
//     conv(a);
//     forn(i, p10[N]) if (ok(i)) {
//         cout << setw(N) << setfill('0') << i << ": " << a[i] << endl;
//     }
//     cout << endl;
//     conv_rev(a);
//     forn(i, p10[N]) if (ok(i)) {
//         cout << setw(N) << setfill('0') << i << ": " << a[i] << endl;
//     }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}