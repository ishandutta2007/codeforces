#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


constexpr lint MOD = 998244353;
template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    constexpr ModInt() : val(0) {}
    constexpr void _setval(lint v) { v = (v % mod) + mod; val = v >= mod ? v - mod : v; }
    constexpr ModInt(lint v) { _setval(v); }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt((lint)val - x.val); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt((lint)val * x.val); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt((lint)val * x.inv()); }
    constexpr ModInt operator-() const { return ModInt(-val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt(a % mod - x.val); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt(a % mod * x.val); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt(a % mod * x.inv()); }
    constexpr bool operator==(const ModInt &x) { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) { return val != x.val; }
    friend istream &operator>>(istream &is, ModInt &x) { lint t; is >> t; x = ModInt(t); return is; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { os << x.val;  return os; }

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
        static vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};
using mint = ModInt<MOD>;


int main()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<int> acc_toji(N);
    vector<int> acc_mitei(N);

    vector<vector<mint>> dpr(N + 1, vector<mint>(N + 1));
    dpr[N][0] = 1;
    IREP(i, N)
    {
        if (S[i] == '(')
        {
            dpr[i] = dpr[i + 1];
        }
        if (S[i] == '?')
        {
            dpr[i] = dpr[i + 1];
            REP(j, N) dpr[i][j + 1] += dpr[i + 1][j];
        }
        if (S[i] == ')')
        {
            IREP(j, N) dpr[i][j + 1] = dpr[i + 1][j];
        }
    }
    REP(i, N + 1)
    {
        IREP(j, N) dpr[i][j] += dpr[i][j + 1];
    }

    vector<mint> cou(N + 1);
    cou[0] = 1;

    mint ret = 0;
    REP(i, N)
    {
        if (S[i] != ')')
        {
            REP(j, N)
            {
                ret += cou[j] * dpr[i + 1][j + 1];
            }

            if (S[i] == '(')
            {
                IREP(i, N) cou[i + 1] = cou[i];
                cou[0] = 0;
            }
            if (S[i] == '?')
            {
                IREP(i, N) cou[i + 1] += cou[i];
            }
        }
    }
    cout << ret << endl;
}