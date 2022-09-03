#include <iostream>
#include <vector>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

template <int mod>
struct ModInt
{
    using lint = long long;
    lint val;
    constexpr ModInt(lint v = 0) noexcept : val(v % mod) { if (val < 0) val += mod; }
    constexpr ModInt operator+(const ModInt &x) const noexcept { return ModInt(*this) += x; }
    constexpr ModInt operator-(const ModInt &x) const noexcept { return ModInt(*this) -= x; }
    constexpr ModInt operator*(const ModInt &x) const noexcept { return ModInt(*this) *= x; }
    constexpr ModInt operator/(const ModInt &x) const noexcept { return ModInt(*this) /= x; }
    constexpr ModInt operator-() const noexcept { return ModInt(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) noexcept { val += x.val; if (val >= mod) val -= mod; return *this; }
    constexpr ModInt &operator-=(const ModInt &x) noexcept { if (val < x.val) val += mod; val -= x.val; return *this; }
    constexpr ModInt &operator*=(const ModInt &x) noexcept { val = val * x.val % mod; return *this; }
    constexpr ModInt &operator/=(const ModInt &x) noexcept { val = val * x.power(mod - 2).val % mod; return *this; }
    constexpr bool operator==(const ModInt &x) const noexcept { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const noexcept { return val != x.val; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { os << x.val;  return os; }
    friend istream &operator>>(istream &is, ModInt &x) { is >> x.val; x.val %= mod; if (x.val < 0) x.val += mod; return is; }
    constexpr ModInt power(lint n) const {
        ModInt ans = 1, tmp = *this;
        while (n) { if (n & 1) ans *= tmp; tmp *= tmp; n >>= 1; }
        return ans;
    }
};
constexpr lint MOD = 998244353;
using mint = ModInt<MOD>;

vector<mint> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<mint>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i;
        inv[i] = -inv[MOD%i] * (MOD / i);
        facInv[i] = facInv[i - 1] * inv[i];
    }
}
mint nCr(int n, int r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return fac[n] * facInv[r] * facInv[n-r];
}
mint nPr(int n, int r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return fac[n] * facInv[n-r];
}
mint power(mint x, lint n)
{
    mint ans = 1;
    while (n>0)
    {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
   return ans;
}
mint doublefac(lint n)
{
    if (n < 0) return 0;
    lint k = (n + 1) / 2;
    if (n & 1) return fac[k * 2] * power(facInv[2], k) * power(fac[k], MOD - 2);
    else return fac[k] * power(facInv[2], k);
}


int main()
{
    int N, K, L;
    cin >> N >> K >> L;
    facInit(N * 2 + 1);

    vector<mint> F(N + 1);
    REP(n, N + 1)
    {
        REP(m, n + 1) F[n] += mint(m % 2 ? - 1 : 1) * nCr(n, m) / (n + m + 1);
        F[n] *= mint(2).power(n);
    }
    mint ret = 0;
    FOR(k, K, N + 1)
    {
        mint tmp = 0;
        REP(i, N - k + 1) tmp += mint(i % 2 ? - 1 : 1) * nCr(N - k, i) * F[k + i];
        ret += tmp * nCr(N, k);
    }
    cout << ret * mint(L) << endl;
}