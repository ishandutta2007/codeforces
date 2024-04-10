#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
using pint = pair<int, int>;

template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    constexpr ModInt() : val(0) {}
    constexpr ModInt &_setval(lint v) { val = (v >= mod ? v - mod : v); return *this; }
    constexpr ModInt(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    constexpr bool operator==(const ModInt &x) const { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
    bool operator<(const ModInt &x) const { return val < x.val; }  // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) { lint t; is >> t; x = ModInt(t); return is; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { os << x.val;  return os; }
    constexpr lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    constexpr lint inv() const { return this->power(mod - 2); }
    constexpr ModInt operator^(lint n) const { return ModInt(this->power(n)); }
    constexpr ModInt &operator^=(lint n) { return *this = *this ^ n; }

    inline ModInt fac() const {
        static std::vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

map<pint, mint> nPrmap;
mint nCr(int n, int r)
{
    mint npr = 1;
    if (!nPrmap.count(pint(n, r)))
    {
        REP(i, r) npr *= n - i;
        nPrmap[pint(n, r)] = npr;
    }
    npr = nPrmap[pint(n, r)];
    return npr / mint(r).fac();
}

int main()
{
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    REP(i, N) cin >> L[i] >> R[i];
    L.push_back(-1);
    R.push_back(-1);
    N++;
    for (auto &x : R) x++;

    set<int> Z;
    for (auto x : L) Z.insert(x);
    for (auto x : R) Z.insert(x);

    vector<int> Y = L;
    Y.insert(Y.end(), R.begin(), R.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    int H = Y.size();

    vector<mint> W(H - 1);
    REP(i, H - 1) W[i] = Y[i + 1] - Y[i];

    vector<vector<mint>> dp(N + 1, vector<mint>(H, 0));
    REP(i, H) dp[0][i] = 1;
    REP(i, N) {
        REP(y, H - 1) {
            mint prb = 1;
            IREP(prv, i + 1)
            {
                if (L[prv] >= Y[y + 1] or R[prv] <= Y[y]) break;
                prb *= mint(W[y]) / (R[prv] - L[prv]);
                dp[i + 1][y] += prb * dp[prv][y + 1] * nCr(i - prv + 1 + W[y].val - 1, i - prv + 1) / mint(W[y]).power(i - prv + 1);
            }
        }
        IREP(y, H - 1) dp[i + 1][y] += dp[i + 1][y + 1];
    }
    cout << dp.back()[0] << endl;
}