#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr lint MOD = 998244353;

vector<int> A;
vector<lint> ret;
vector<int> Q;

map<int, int> m;
constexpr int NMAX = 300010;


vector<lint> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<lint>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        facInv[i] = facInv[i-1] * inv[i] % MOD;
    }
}
lint nCr(lint n, lint r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return (fac[n] * facInv[r] % MOD) * facInv[n-r] % MOD;
}
lint nPr(lint n, lint r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return fac[n] * facInv[n-r] % MOD;
}

lint power(lint x, lint n, lint MOD)
{
    lint ans = 1;
    while (n>0)
    {
        if (n & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
       n >>= 1;
    }
   return ans;
}
// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
// mod: , primitive_root: mod is_inverse: true
void fft_mod(vector<lint> &a, lint mod, lint primitive_root, bool is_inverse=false)
{
    int n = a.size();
    lint h = power(primitive_root, (mod - 1) / n, mod);
    if (is_inverse) h = mod_inverse(h, mod);

    int i = 0;
    FOR(j, 1, n - 1) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    for (int m = 1; m < n; m *= 2) {
        int m2 = 2 * m;
        lint base = power(h, n / m2, mod);
        lint w = 1;
        REP(x, m) {
            for (int s = x; s < n; s += m2) {
                lint u = a[s], d = a[s + m] * w % mod;
                a[s] = u + d - (u + d >= mod ? mod : 0), a[s + m] = u - d + (u - d < 0 ? mod : 0);
            }
            w = w * base % mod;
        }
    }
    for (auto &v : a) v = (v < 0 ? v + mod : v);
    if (is_inverse)
    {
        lint n_inv = mod_inverse(n, mod);
        for (auto &v : a) v = v * n_inv % mod;
    }
}
// MOD mod retval[i] = \sum_j a[j] b[i - j]
vector<lint> convolution_mod(vector<lint> a, vector<lint> b, lint mod, lint primitive_root)
{
    int sz = 1;
    while (sz < a.size() + b.size()) sz <<= 1;
    a.resize(sz), b.resize(sz);
    fft_mod(a, mod, primitive_root, false), fft_mod(b, mod, primitive_root, false);
    REP(i, sz) a[i] = a[i] * b[i] % mod;
    fft_mod(a, mod, primitive_root, true);
    return a;
}

void solve(lint b)
{
    int n1 = 0, n2 = 0;
    for (auto p : m) if (p.first < b)
    {
        if (p.second == 1) n1++;
        if (p.second > 1) n2++;
    }
    vector<lint> u(n1 + 1), v(1 + n2 * 2);
    REP(i, n1 + 1) u[i] = nCr(n1, i) * power(2, i, MOD) % MOD;
    REP(i, n2 * 2 + 1) v[i] = nCr(n2 * 2, i);
    vector<lint> conv = convolution_mod(u, v, MOD, 3);
    REP(i, Q.size())
    {
        int len = Q[i] / 2 - b - 1;
        if (len < 0) continue;
        if (len < (int)conv.size()) ret[i] += conv[len];
    }
}

int main()
{
    facInit(NMAX * 2);
    int N, K;
    cin >> N >> K;
    A.resize(N);
    cin >> A;
    for (auto a : A) m[a]++;

    vector<int> B(K);
    cin >> B;
    int q;
    cin >> q;
    ret.resize(q);
    Q.resize(q);
    cin >> Q;
    for (auto b : B)
    {
        solve(b);
    }
    for (auto ans : ret)
    {
        printf("%lld\n", ans % MOD);
    }
}