#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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

vector<mint> P, PA, PAA;
mint ret;
set<int> s;
vector<int> one;

mint get_prob(int l, int r)
{
    mint pprod = PA[r - 1] / PA[l - 1];
    if (one[r - 1] - one[l - 1] == r - l)
    {
        return r - l;
    }

    mint mr = (PAA[r - 2] - PAA[l - 1]) / PA[l - 1] + 1 - (PA[r - 1] / PA[l - 1]) * (r - l);

    return (pprod * (r - l) + mr) / pprod;
}
void eraser(int n)
{
    int lo = *prev(s.lower_bound(n));
    int hi = *s.upper_bound(n);
    mint m = get_prob(lo, hi);
    mint m1 = get_prob(lo, n);
    mint m2 = get_prob(n, hi);
    ret = ret - m1 - m2 + m;
}
void adder(int n)
{
    int lo = *prev(s.lower_bound(n));
    int hi = *s.upper_bound(n);
    mint m = get_prob(lo, hi);
    mint m1 = get_prob(lo, n);
    mint m2 = get_prob(n, hi);
    ret = ret + m1 + m2 - m;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    P.resize(N);
    one.resize(N + 2);
    REP(i, N)
    {
        int p;
        cin >> p;
        P[i] = mint(p) / 100;
        if (p == 100) one[i + 1] = 1;
    }
    REP(i, N + 1) one[i + 1] += one[i];

    PA.assign(N + 1, 1);
    REP(i, N) PA[i + 1] = PA[i] * P[i];
    PAA.resize(N + 1);
    PAA[0] = 1;
    REP(i, N) PAA[i + 1] = PA[i + 1] + PAA[i];
    s.insert(1);
    s.insert(N + 1);
    ret = get_prob(1, N + 1);
    REP(_, Q)
    {
        int u;
        cin >> u;
        if (s.count(u))
        {
            eraser(u);
            s.erase(u);
        }
        else
        {
            adder(u);
            s.insert(u);
        }
        printf("%d\n", ret.val);
    }
}