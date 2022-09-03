#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

struct ModIntRuntime
{
    using lint = long long int;
    int val;
    static int &mod()
    {
        static int mod_ = 0;
        return mod_;
    }
    static vector<ModIntRuntime> &facs()
    {
        static vector<ModIntRuntime> facs_;
        return facs_;
    }
    static void set_mod(const int &m) {
        if (mod() != m) facs().clear();
        mod() = m;
    }

    void _setval(lint v) { v = (v % mod()) + mod(); this->val = v >= mod() ? v - mod() : v; }
    ModIntRuntime(lint v = 0) { _setval(v); }
    ModIntRuntime operator+(const ModIntRuntime &x) const { return ModIntRuntime((lint)val + x.val); }
    ModIntRuntime operator-(const ModIntRuntime &x) const { return ModIntRuntime((lint)val - x.val); }
    ModIntRuntime operator*(const ModIntRuntime &x) const { return ModIntRuntime((lint)val * x.val); }
    ModIntRuntime operator/(const ModIntRuntime &x) const { return ModIntRuntime((lint)val * x.inv()); }
    ModIntRuntime operator-() { return ModIntRuntime(-val); }
    ModIntRuntime &operator+=(const ModIntRuntime &x) { return *this = *this + x; }
    ModIntRuntime &operator-=(const ModIntRuntime &x) { return *this = *this - x; }
    ModIntRuntime &operator*=(const ModIntRuntime &x) { return *this = *this * x; }
    ModIntRuntime &operator/=(const ModIntRuntime &x) { return *this = *this / x; }
    friend ModIntRuntime operator+(lint a, const ModIntRuntime &x) { return ModIntRuntime(a % mod() + x.val); }
    friend ModIntRuntime operator-(lint a, const ModIntRuntime &x) { return ModIntRuntime(a % mod() - x.val); }
    friend ModIntRuntime operator*(lint a, const ModIntRuntime &x) { return ModIntRuntime(a % mod() * x.val); }
    friend ModIntRuntime operator/(lint a, const ModIntRuntime &x) { return ModIntRuntime(a % mod() * x.inv()); }
    bool operator==(const ModIntRuntime &x) const { return val == x.val; }
    bool operator!=(const ModIntRuntime &x) const { return val != x.val; }
    friend istream &operator>>(istream &is, ModIntRuntime &x) { lint t; is >> t; x = ModIntRuntime(t); return is; }
    friend ostream &operator<<(ostream &os, const ModIntRuntime &x) { os << x.val;  return os; }

    lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod();
            tmp = tmp * tmp % mod();
            n /= 2;
        }
        return ans;
    }
    lint inv() const { return this->power(mod() - 2); }
    ModIntRuntime operator^(lint n) const { return ModIntRuntime(this->power(n)); }
    ModIntRuntime &operator^=(lint n) { return *this = *this ^ n; }

    ModIntRuntime fac() const {
        int l0 = facs().size();
        if (l0 > this->val) return facs()[this->val];

        facs().resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs()[i] = (i == 0 ? ModIntRuntime(1) : facs()[i - 1] * ModIntRuntime(i));
        return facs()[this->val];
    }

    ModIntRuntime doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModIntRuntime(k * 2).fac() / ModIntRuntime(2).power(k) / ModIntRuntime(k).fac();
        else return ModIntRuntime(k).fac() * ModIntRuntime(2).power(k);
    }

    ModIntRuntime nCr(const ModIntRuntime &r) const {
        if (this->val < r.val) return ModIntRuntime(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};
using mint = ModIntRuntime;

int main()
{
    mint::set_mod(998244353);
    string S;
    cin >> S;
    int N = S.length();
    vector<int> c_l(N), c_lr(N);
    REP(i, N)
    {
        if (S[i] == '(') c_l[i]++;
        if (S[i] == '?') c_lr[i]++;
    }
    REP(i, N - 1)
    {
        c_l[i + 1] += c_l[i];
        c_lr[i + 1] += c_lr[i];
    }

    mint ret = 0;
    FOR(n_l, c_l.back(), c_l.back() + c_lr.back() + 1)
    {
        int r = N - n_l;
        int l_left = (r ? c_l[r - 1] : 0);
        int lr_left = (r ? c_lr[r - 1] : 0);
        ret += l_left * mint(c_lr.back()).nCr(n_l - c_l.back()) + (c_lr.back() ? lr_left * mint(c_lr.back() - 1).nCr(n_l - 1 - c_l.back()) : 0);
    }
    cout << ret << endl;
}