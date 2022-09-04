#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

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
};
using mint = ModInt<998244353>;

vector<vector<int>> to;

struct T {
    mint dp0, dp1, dpnotuse;
    mint sum0, sum1, sumnotuse;
    T() : dp0(0), dp1(0), dpnotuse(1), sum0(0), sum1(0), sumnotuse(0) {}
    friend std::ostream &operator<<(std::ostream &os, const T &x) {
        os << "(" << x.dp0 << "," << x.dp1 << "," << x.dpnotuse << ";" << x.sum0 << "," << x.sum1 << "," << x.sumnotuse << ")";
        return os;
    }
};

T merge(T root, const T chi) {
    root.dp0 = root.dp0 * (chi.dp0 * 2 + chi.dp1 * 2 + chi.dpnotuse * 3) + root.dpnotuse * (chi.dp0 + chi.dp1 + chi.dpnotuse * 2);
    root.dp1 = root.dp1 * (chi.dp0 * 2 + chi.dp1 + chi.dpnotuse * 2) + root.dpnotuse * (chi.dp0 + chi.dpnotuse);
    root.dpnotuse *= (chi.dp0 + chi.dp1 + chi.dpnotuse);
    return root;
}

vector<T> dp;
void dfs(int now, int prv) {
    dp[now] = T();
    for (auto nxt : to[now]) if (nxt != prv) {
        dfs(nxt, now);
        dp[now] = merge(dp[now], dp[nxt]);
    }
}
mint ret;


int main()
{
    int N;
    cin >> N;
    to.resize(N + 1);
    REP(_, N - 1) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    dp.resize(N + 1);
    dfs(1, 0);
    // dbg(dp);
    cout << dp[1].dp0 + dp[1].dp1 + dp[1].dpnotuse - 1 << "\n";
}