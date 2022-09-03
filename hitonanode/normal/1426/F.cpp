#include <bits/stdc++.h>
using namespace std;

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
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { os << x.val;  return os; }
};
using mint = ModInt<1000000007>;

int main()
{
    string S;
    cin >> S >> S;
    mint dp0 = 1, dp1 = 0, dp2 = 0, ret = 0;
    for (auto c : S)
    {
        if (c == 'a') dp1 += dp0;
        if (c == 'b') dp2 += dp1;
        if (c == 'c') ret += dp2;
        if (c == '?')
        {
            ret *= 3;
            ret += dp2;
            dp2 *= 3;
            dp2 += dp1;
            dp1 *= 3;
            dp1 += dp0;
            dp0 *= 3;
        }
    }
    cout << ret << '\n';
}