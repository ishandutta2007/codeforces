#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

template <int mod>
struct ModInt
{
    using lint = long long;
    static int get_mod() { return mod; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&](){
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac) if (ModInt(g).power((mod - 1) / i) == 1) { ok = false; break; }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
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

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (power((mod - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.power((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModInt x = power((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModInt z = b.power(m);
        while (y != 1) {
            int j = 0;
            ModInt t = y;
            while (t != 1) j++, t *= t;
            z = z.power(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModInt(std::min(x.val, mod - x.val));
    }
};
using mint = ModInt<1000000007>;

// Fast Walsh-Hadamard transform
// Tutorials: <https://codeforces.com/blog/entry/71899>
//            <https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it>
template <typename T, typename F>
void walsh_hadamard(std::vector<T>& seq, F f)
{
    const int n = seq.size();
    assert(__builtin_popcount(n) == 1);
    for (int w = 1; w < n; w *= 2) {
        for (int i = 0; i < n; i += w * 2) {
            for (int j = 0; j < w; j++) {
                f(seq[i + j], seq[i + j + w]);
            }
        }
    }
}

template <typename T, typename F1, typename F2>
std::vector<T> walsh_hadamard_conv(std::vector<T> x, std::vector<T> y, F1 f, F2 finv)
{
    const int n = x.size();
    assert(__builtin_popcount(n) == 1);
    assert(x.size() == y.size());
    if (x == y) {
        walsh_hadamard(x, f), y = x;
    } else {
        walsh_hadamard(x, f), walsh_hadamard(y, f);
    }
    for (size_t i = 0; i < x.size(); i++) {
        x[i] *= y[i];
    }
    walsh_hadamard(x, finv);
    return x;
}

// bitwise xor convolution
// ret[i] = \sum_j x[j] * y[i ^ j]
// if T is integer, ||x||_1 * ||y||_1 * 2 < numeric_limits<T>::max()
template <typename T>
std::vector<T> xorconv(std::vector<T> x, std::vector<T> y)
{
    auto f = [](T& lo, T& hi) {
        T c = lo + hi;
        hi = lo - hi, lo = c;
    };
    auto finv = [](T& lo, T& hi) {
        T c = lo + hi;
        // hi = (lo - hi) / 2, lo = c / 2;
        hi = (lo - hi), lo = c;
    };
    return walsh_hadamard_conv(x, y, f, finv);
}

int main()
{
    int N;
    cin >> N;
    string str;
    cin >> str;
    mint ret = 0;
    vector<long long> xc(str.size());
    REP(i, str.size()) {
        xc[i] = (str[i] == '1');
    }
    xc = xorconv(xc, xc);
    vector<mint> pow2(N + 2);

    REP(i, pow2.size()) pow2[i] = mint(2).power(i);

    REP(S, str.size()) {
        ret += pow2[N - __builtin_popcount(S)] * xc[S];
    }
    cout << ret * 3 / str.size() << '\n';
}