#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = 998244353;

const int N = (int)1.01e6;

void print(vector<int> a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int fct[N], ofct[N];

void add(int &a, ll b) {
    a = (a + b) % MOD;
}

int getC(int n, int k) {
    if (k < 0 || n < k || n < 0) return 0;
    return 1LL * fct[n] * ofct[k] % MOD * ofct[n - k] % MOD;
}

int bin(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}


void init() {
    fct[0] = 1;
    for (int i = 1; i < N; i++) fct[i] = 1LL * fct[i - 1] * i % MOD;
    ofct[N - 1] = inv(fct[N - 1]);
    for (int i = N - 2; i >= 0; i--) ofct[i] = 1LL * ofct[i + 1] * (i + 1) % MOD;
}

#define forn(i, n) for (int i = 0; i < (n); i++)

namespace fft
{
    const int maxBase = 18;
    const int maxN = 1 << maxBase;

    struct num
    {
        dbl x, y;
        num(){}
        num(dbl xx, dbl yy): x(xx), y(yy) {}
        num(dbl alp): x(cos(alp)), y(sin(alp)) {}
    };

    inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }

    const dbl PI = acos(-1);

    num root[maxN];
    int rev[maxN];
    bool rootsPrepared = false;

    void prepRoots()
    {
        if (rootsPrepared) return;
        rootsPrepared = true;
        root[1] = num(1, 0);
        for (int k = 1; k < maxBase; ++k)
        {
            num x(2 * PI / pw(k + 1));
            for (int i = pw(k - 1); i < pw(k); ++i)
            {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        }
    }

    int base, N;

    int lastRevN = -1;
    void prepRev()
    {
        if (lastRevN == N) return;
        lastRevN = N;
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }

    void fft(num *a, num *f)
    {
        forn(i, N) f[i] = a[rev[i]];
        for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
                {
                    num z = f[i + j + k] * root[j + k];
                    f[i + j + k] = f[i + j] - z;
                    f[i + j] = f[i + j] + z;
                }
    }

    num a[maxN], b[maxN], f[maxN], g[maxN];
    ll A[maxN], B[maxN], C[maxN];

    void _multMod(int mod, bool eq)
    {
        forn(i, N)
        {
            int x = A[i] % mod;
            a[i] = num(x & (pw(15) - 1), x >> 15);
        }
        forn(i, N)
        {
            int x = B[i] % mod;
            b[i] = num(x & (pw(15) - 1), x >> 15);
        }
        fft(a, f);
        if (!eq) {
            fft(b, g);
        } else {
            for (int i = 0; i < N; i++) g[i] = f[i];
        }

        forn(i, N)
        {
            int j = (N - i) & (N - 1);
            num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
            num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
            num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
            num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
            a[j] = a1 * b1 + a2 * b2 * num(0, 1);
            b[j] = a1 * b2 + a2 * b1;
        }

        fft(a, f);
        fft(b, g);

        forn(i, N)
        {
            ll aa = f[i].x + 0.5;
            ll bb = g[i].x + 0.5;
            ll cc = f[i].y + 0.5;
            C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
        }
    }

    void prepAB(int n1, int n2)
    {
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;

        prepRoots();
        prepRev();
    }

    /*void mult(int n1, int n2)
    {
        prepAB(n1, n2);
        forn(i, N) a[i] = num(A[i], B[i]);
        fft(a, f);
        forn(i, N)
        {
            int j = (N - i)  & (N - 1);
            a[i] = (f[j] * f[j] - conj(f[i] * f[i])) * num(0, -0.25 / N);
        }
        fft(a, f);
        forn(i, N) C[i] = (ll)round(f[i].x);
    }*/


    void mult(int n1, int n2, int mod, bool eq)
    {
        prepAB(n1, n2);
        _multMod(mod, eq);
    }

    // HOW TO USE ::
    // -- set correct maxBase
    // -- use mult(n1, n2), multMod(n1, n2, mod) and multLL(n1, n2)
    // -- input  : A[], B[]
    // -- output : C[]
}



int slowSubsolve(int n, int a) {
    if (a == 0) {
        return n == 0;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = 0;
    do {
        int cur = -1;
        int cnt = 0;
        for (int x : p) {
            if (x > cur) {
                cur = x;
                cnt++;
            }
        }
        ans += cnt == a;
    } while (next_permutation(p.begin(), p.end()));
    return ans;
}

vector<int> mul(const vector<int> &a, const vector<int> &b, int k, bool eq = 0) {
    for (int i = 0; i < k; i++) {
        fft::A[i] = a[i];
        fft::B[i] = b[i];
    }
    fft::mult(k, k, MOD, eq);
    vector<int> c(k);
    for (int i = 0; i < k; i++) c[i] = fft::C[i];
    return c;
}

/*vector<int> bin(vector<int> a, int n, int k) {
    vector<int> res(k);
    res[0] = 1;
    while (n) {
        if (n & 1) res = mul(res, a, k);
        a = mul(a, a, k, 1);
        n >>= 1;
    }
    return res;
}

vector<int> fastSubsolve(int m, int n) {
    vector<int> f(n);
    for (int i = 1; i < n; i++) {
        //f[i] = inv(i);
        f[i] = 1LL * ofct[i] * fct[i - 1] % MOD;
        if (i % 2 == 0) f[i] = (MOD - f[i]) % MOD;
    }
    f = bin(f, m, n);
    int o = ofct[m];
    for (int i = 0; i < n; i++) {
        f[i] = 1LL * f[i] * o % MOD;
    }
    for (int i = 0; i < n; i++) {
        f[i] = 1LL * f[i] * fct[i] % MOD;
    }
    for (int i = 0; i < n; i++) {
        if ((i - m) % 2 != 0) {
            f[i] = (MOD - f[i]) % MOD;
        }
    }
    return f;
}*/

pair<vector<int>, vector<int>> bin(vector<int> a, int n1, int n2, int k) {
    vector<int> res1(k);
    res1[0] = 1;
    auto res2 = res1;
    while (n1 || n2) {
        if (n1 & 1) res1 = mul(res1, a, k);
        n1 >>= 1;

        if (n2 & 1) res2 = mul(res2, a, k);
        n2 >>= 1;

        a = mul(a, a, k, 1);
    }
    return {res1, res2};
}

vector<vector<int>> fastSubsolve(int m1, int m2, int n) {
    vector<int> f(n);
    for (int i = 1; i < n; i++) {
        //f[i] = inv(i);
        f[i] = 1LL * ofct[i] * fct[i - 1] % MOD;
        if (i % 2 == 0) f[i] = (MOD - f[i]) % MOD;
    }
    auto ff = bin(f, m1, m2, n);

    vector<vector<int>> res;
    for (int it = 0; it < 2; it++) {
        f = ff.first;

        int o = ofct[m1];
        for (int i = 0; i < n; i++) {
            f[i] = 1LL * f[i] * o % MOD;
        }
        for (int i = 0; i < n; i++) {
            f[i] = 1LL * f[i] * fct[i] % MOD;
        }
        for (int i = 0; i < n; i++) {
            if ((i - m1) % 2 != 0) {
                f[i] = (MOD - f[i]) % MOD;
            }
        }
        res.push_back(f);

        swap(m1, m2);
        swap(ff.first, ff.second);
    }
    return res;
}


int slow(int n, int a, int b) {
    if (a == 0 || b == 0) return 0;

    int ans = 0;
    for (int x = 0; x < n; x++) {
        add(ans, 1LL * getC(n - 1, x) * slowSubsolve(x, a - 1) % MOD * slowSubsolve(n - 1 - x, b - 1));
    }
    return ans;
}

int fast(int n, int a, int b) {
    if (a == 0 || b == 0) return 0;

    //vector<int> va = fastSubsolve(a - 1, n);
    //vector<int> vb = fastSubsolve(b - 1, n);
    auto o = fastSubsolve(a - 1, b - 1, n);
    auto va = o[0];
    auto vb = o[1];
    //print(va);
    //print(vb);

    int ans = 0;
    for (int x = 0; x < n; x++) {
        //add(ans, 1LL * getC(n - 1, x) * slowSubsolve(x, a - 1) % MOD * slowSubsolve(n - 1 - x, b - 1));
        add(ans, 1LL * getC(n - 1, x) * va[x] % MOD * vb[n - 1 - x]);
    }
    return ans;
}



int main() {
    init();
    //fft::init();
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    if (0) {
        int A = (1 << 15) - 1;
        cout << fast(1e5, A, A) << endl;
        cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
        return 0;
    }
    if (0) {
        for (int n = 1; n <= 10; n++) {
            cout << n << endl;
            for (int a = 0; a <= n; a++) {
                for (int b = 0; b <= n; b++) {
                    int ans1 = fast(n, a, b);
                    int ans2 = slow(n, a, b);
                    assert(ans1 == ans2);
                }
            }
        }
        return 0;
    }
    /*{
        for (int n = 1; n <= 5; n++) {
            for (int a = 1; a <= n; a++) {
                cout << slowSubsolve(n, a) << " ";
            }
            cout << endl;
        }
        auto v = fastSubsolve(3, 9);
        print(v);
        return 0;
    }*/

    int n, a, b;
    while (cin >> n >> a >> b) {
        cout << fast(n, a, b) << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}