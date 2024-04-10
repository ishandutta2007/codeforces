#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

struct ModIntRuntime
{
    using lint = long long int;
    static int get_mod() { return mod; }
    int val;
    static int mod;
    static std::vector<ModIntRuntime> &facs()
    {
        static std::vector<ModIntRuntime> facs_;
        return facs_;
    }
    static int &get_primitive_root() {
        static int primitive_root_ = 0;
        if (!primitive_root_) {
            primitive_root_ = [&](){
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac) if (ModIntRuntime(g).power((mod - 1) / i) == 1) { ok = false; break; }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root_;
    }
    static void set_mod(const int &m) {
        if (mod != m) facs().clear();
        mod = m;
        get_primitive_root() = 0;
    }
    ModIntRuntime &_setval(lint v) { val = (v >= mod ? v - mod : v); return *this; }
    ModIntRuntime() : val(0) {}
    ModIntRuntime(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    ModIntRuntime operator+(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val + x.val); }
    ModIntRuntime operator-(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val - x.val + mod); }
    ModIntRuntime operator*(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val * x.val % mod); }
    ModIntRuntime operator/(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val * x.inv() % mod); }
    ModIntRuntime operator-() const { return ModIntRuntime()._setval(mod - val); }
    ModIntRuntime &operator+=(const ModIntRuntime &x) { return *this = *this + x; }
    ModIntRuntime &operator-=(const ModIntRuntime &x) { return *this = *this - x; }
    ModIntRuntime &operator*=(const ModIntRuntime &x) { return *this = *this * x; }
    ModIntRuntime &operator/=(const ModIntRuntime &x) { return *this = *this / x; }
    friend ModIntRuntime operator+(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod + x.val); }
    friend ModIntRuntime operator-(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod - x.val + mod); }
    friend ModIntRuntime operator*(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod * x.val % mod); }
    friend ModIntRuntime operator/(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod * x.inv() % mod); }
    bool operator==(const ModIntRuntime &x) const { return val == x.val; }
    bool operator!=(const ModIntRuntime &x) const { return val != x.val; }
    bool operator<(const ModIntRuntime &x) const { return val < x.val; }  // To use std::map<ModIntRuntime, T>
    friend std::istream &operator>>(std::istream &is, ModIntRuntime &x) { lint t; is >> t; x = ModIntRuntime(t); return is; }
    friend std::ostream &operator<<(std::ostream &os, const ModIntRuntime &x) { os << x.val;  return os; }
 
    lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    lint inv() const { return this->power(mod - 2); }
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

    ModIntRuntime sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (power((mod - 1) / 2) != 1) return 0;
        ModIntRuntime b = 1;
        while (b.power((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModIntRuntime x = power((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModIntRuntime z = b.power(m);
        while (y != 1) {
            int j = 0;
            ModIntRuntime t = y;
            while (t != 1) j++, t *= t;
            z = z.power(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModIntRuntime(std::min(x.val, mod - x.val));
    }
};
int ModIntRuntime::mod = 1;

using mint = ModIntRuntime;

int main()
{
    int N, M;
    cin >> N >> M;
    ModIntRuntime::set_mod(M);
    mint ans = 0;
    FOR(l, 1, N + 1) {
        mint tmp = mint(N + 1 - l) * mint(N + 1 - l) * mint(l).fac() * mint(N - l).fac();
        ans += tmp;
    }
    cout << ans << endl;
}