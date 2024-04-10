#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;


namespace n_mint {
    template<typename T>
    T inverse(T a, T m) {
        T u = 0, v = 1;
        while (a != 0) {
            T t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }
    template<typename T>
    class Mint {
    public:
        using Arg = T;
        using Type = typename decay<decltype(T::value)>::type;
        constexpr Mint() : value() {}
        template<typename U>
        Mint(const U &x) {
            value = normalize(x);
        }
        template<typename U>
        static Type normalize(const U &x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }
        const Type &operator()() const { return value; }
        template<typename U>
        explicit operator U() const { return static_cast<U>(value); }
        constexpr static Type mod() { return T::value; }
        Mint &operator+=(const Mint &other) {
            if ((value += other.value) >= mod()) value -= mod();
            return *this;
        }
        Mint &operator-=(const Mint &other) {
            if ((value -= other.value) < 0) value += mod();
            return *this;
        }
        template<typename U>
        Mint &operator+=(const U &other) { return *this += Mint(other); }
        template<typename U>
        Mint &operator-=(const U &other) { return *this -= Mint(other); }
        Mint &operator++() { return *this += 1; }
        Mint &operator--() { return *this -= 1; }
        const Mint operator++(int) {
            Mint result(*this);
            *this += 1;
            return result;
        }
        const Mint operator--(int) {
            Mint result(*this);
            *this -= 1;
            return result;
        }
        Mint operator-() const { return Mint(-value); }
        template<typename U = T>
        typename enable_if<is_same<typename Mint<U>::Type, int>::value, Mint>::type &operator*=(const Mint &rhs) {
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
            return *this;
        }
        template<typename U = T>
        typename enable_if<is_same<typename Mint<U>::Type, int64_t>::value, Mint>::type &operator*=(const Mint &rhs) {
            auto q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }
        template<typename U = T>
        typename enable_if<!is_integral<typename Mint<U>::Type>::value, Mint>::type &operator*=(const Mint &rhs) {
            value = normalize(value * rhs.value);
            return *this;
        }
        Mint &operator/=(const Mint &other) { return *this *= Mint(inverse(other.value, mod())); }
        Mint inv() const { return Mint(inverse(value, mod())); }
        template<typename U>
        friend bool operator==(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend bool operator<(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend bool operator>(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend std::istream &operator>>(std::istream &stream, Mint<U> &number);
    private:
        Type value;
    };
    template<typename T>
    Mint<T> abs(const Mint<T> &val) { return val; }
    template<typename T>
    bool operator==(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value == rhs.value; }
    template<typename T, typename U>
    bool operator==(const Mint<T> &lhs, U rhs) { return lhs == Mint<T>(rhs); }
    template<typename T, typename U>
    bool operator==(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) == rhs; }
    template<typename T>
    bool operator!=(const Mint<T> &lhs, const Mint<T> &rhs) { return !(lhs == rhs); }
    template<typename T, typename U>
    bool operator!=(const Mint<T> &lhs, U rhs) { return !(lhs == rhs); }
    template<typename T, typename U>
    bool operator!=(U lhs, const Mint<T> &rhs) { return !(lhs == rhs); }
    template<typename T>
    bool operator<(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value < rhs.value; }
    template<typename T>
    bool operator>(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value > rhs.value; }
    template<typename T>
    Mint<T> operator+(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T, typename U>
    Mint<T> operator+(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T, typename U>
    Mint<T> operator+(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T>
    Mint<T> operator-(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T, typename U>
    Mint<T> operator-(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T, typename U>
    Mint<T> operator-(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T>
    Mint<T> operator*(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T, typename U>
    Mint<T> operator*(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T, typename U>
    Mint<T> operator*(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T>
    Mint<T> operator/(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> operator/(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> operator/(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> bin(const Mint<T> &a, const U &b) {
        assert(b >= 0);
        Mint<T> x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
    template <typename T>
    Mint<T> inv(const Mint<T> &a) {
        return inverse(a(), Mint<T>::mod());
    }
    template<typename T>
    string to_string(const Mint<T> &number) {
        return std::to_string(number());
    }
    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const Mint<T> &number) {
        return stream << number();
    }
    template<typename T>
    std::istream &operator>>(std::istream &stream, Mint<T> &number) {
        typename common_type<typename Mint<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Mint<T>::normalize(x);
        return stream;
    }
    template<typename T, typename Enabled = void>
    struct is_modular : std::false_type {};
    template<typename T>
    struct is_modular<T, typename enable_if<
            is_same<T, Mint<typename T::Arg>>::value &&
            is_integral<typename T::Type>::value
    >::type> : true_type {};
    struct DynamicMod {
        static int value;
    };
    constexpr int MOD = 998244353;
    using mint = Mint<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;
}
using namespace n_mint;

void print(vector<mint> a) {
    for (int i = 0; i < (int)a.size(); i++) {
        printf("%d%c", a[i](), " \n"[i + 1 == (int)a.size()]);
    }
}

vector<mint> solve(int m, vector<ll> a) {
    int n = a.size();

    vector<int> at(m);
    vector<ll> lb(m);
    for (ll x : a) {
        for (int i = 0; i < m; i++) {
            if (x & (1LL << i)) {
                if (!at[i]) {
                    lb[i] = x;
                    at[i] = 1;
                    break;
                }
                x ^= lb[i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (at[i]) {
            for (int j = 0; j < m; j++) {
                if (j == i || !at[j]) continue;
                if (lb[j] & (1LL << i)) {
                    lb[j] ^= lb[i];
                }
            }
        }
    }

    vector<ll> basis;
    vector<ll> free;
    ll basis_mask = 0;
    for (int i = 0; i < m; i++) {
        assert((at[i] != 0) == (lb[i] != 0));
        if (at[i]) {
            basis.push_back(lb[i]);
            basis_mask |= 1LL << i;
        } else {
            free.push_back(i);
        }
    }
//    db2(basis.size(), free.size());


    vector<mint> ans(m + 1);
    if (basis.size() <= free.size()) {
        for (int mask = 0; mask < (1LL << (int)basis.size()); mask++) {
            ll xr = 0;
            for (int i = 0; i < (int)basis.size(); i++) {
                if (mask & (1LL << i)) {
                    xr ^= basis[i];
                }
            }
            int cnt = __builtin_popcountll(xr);
            ans[cnt] += 1;
        }
    } else {
        vector<ll> nb;
        int k = free.size();
        for (ll x : basis) {
            ll cur = 0;
            for (int i = 0; i < k; i++) {
                if (x & (1LL << free[i])) {
                    cur |= 1LL << i;
                }
            }
            nb.push_back(cur);
        }

        vector<vector<mint>> dp(basis.size() + 1, vector<mint>(1 << k));
        dp[0][0] = 1;
        for (ll x : nb) {
            vector<vector<mint>> ndp(basis.size() + 1, vector<mint>(1 << k));
            for (int i = 0; i < (int) dp.size(); i++) {
                for (int j = 0; j < (int) dp[i].size(); j++) {
                    if (dp[i][j]() == 0) continue;
                    assert(i + 1 < (int) ndp.size());
                    assert((j ^ x) < (int) ndp[i + 1].size());
                    ndp[i][j] += dp[i][j];
                    ndp[i + 1][j ^ x] += dp[i][j];
                }
            }
            dp = ndp;
        }

        for (int i = 0; i < (int) dp.size(); i++) {
            for (int j = 0; j < (int) dp[i].size(); j++) {
                if (dp[i][j] == 0) continue;
                int cnt = i + __builtin_popcountll(j);
                ans[cnt] += dp[i][j];
            }
        }
    }
    for (auto &x : ans) {
        x = x * bin((mint)2, n - (int)basis.size());
    }

    return ans;
}

vector<mint> slow(int m, vector<ll> a) {
    int n = a.size();
    vector<mint> ans(m + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
        ll xr = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                xr ^= a[i];
            }
        }
        ans[__builtin_popcountll(xr)] += 1;
    }
    return ans;
}

void stress() {
    for (int it = 9;; it++) {
        db(it);
        mt19937_64 rnd(it);

        int n = rnd() % 15 + 1;
//        int m = rnd() % 36;
        int m = 35;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) a[i] = rnd() % (1LL << m);

        auto ans1 = solve(m, a);
        auto ans2 = slow(m, a);
        if (ans1 != ans2) {
            dbv(ans1);
            dbv(ans2);
            db2(n, m);
            dbv(a);
            exit(0);
        }
        for (int i = 0; i <= m; i++) assert(ans1[i]() == ans2[i]());
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    stress();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        print(solve(m, a));
    }

    return 0;
}