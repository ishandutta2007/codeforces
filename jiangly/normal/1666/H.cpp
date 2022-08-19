#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>

#include <utility>

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast moduler by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m`
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (long long a : {2, 7, 61}) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

long long pow_mod(long long x, long long n, int m) {
    assert(0 <= n && 1 <= m);
    if (m == 1) return 0;
    internal::barrett bt((unsigned int)(m));
    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
    while (n) {
        if (n & 1) r = bt.mul(r, y);
        y = bt.mul(y, y);
        n >>= 1;
    }
    return r;
}

long long inv_mod(long long x, long long m) {
    assert(1 <= m);
    auto z = internal::inv_gcd(x, m);
    assert(z.first == 1);
    return z.second;
}

// (rem, mod)
std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = internal::inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};

        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

}  // namespace atcoder


using i64 = long long;

i64 floorSum(i64 n, i64 m, i64 a, i64 b = 0) {
    return n * (n - 1) / 2 * (a / m) + atcoder::floor_sum(n, m, a % m, b);
}

std::vector<std::array<i64, 2>> getHull(i64 x, i64 d, i64 h) {
    std::vector<std::array<i64, 2>> p;
    p.push_back({0LL, 0LL});
    i64 l = 1;
    while (l <= x) {
        // std::cerr << l << " " << x << "\n";
        // min l<=i<=x id mod h
        i64 L = 0, R = h - 1;
        while (L < R) {
            i64 m = (L + R + 1) / 2;
            if (floorSum(x + 1, h, d) - floorSum(l, h, d) + x - l + 1 ==
                floorSum(x + 1, h, d, h - m) - floorSum(l, h, d, h - m)) {
                L = m;
            } else {
                R = m - 1;
            }
        }
        i64 mn = L;
        L = l, R = x;
        while (L < R) {
            i64 m = (L + R + 1) / 2;
            if (mn == h - 1 ||
                floorSum(x + 1, h, d) - floorSum(m, h, d) + x - m + 1 ==
                floorSum(x + 1, h, d, h - mn - 1) - floorSum(m, h, d, h - mn - 1)) {
                R = m - 1;
            } else {
                L = m;
            }
        }
        i64 v = L;
        // std::cerr << "v : " << v << "\n";
        i64 g = v - l + 1;
        v = l - 1 + (x - l + 1) / g * g;
        p.push_back({v, v * d / h});
        l = v + 1;
    }
    // for (auto [x, y] : p) {
    //     std::cerr << x << " " << y << "\n";
    // }
    return p;
}   
void solve() {
    int n;
    i64 d, h;
    std::cin >> n >> d >> h;
    
    i64 ans = 1;
    std::vector<i64> r(n);
    std::vector<std::array<i64, 2>> b;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        i64 x = (a * h + d - 1) / d;
        // i64 v = 0;
        // if (a - (x - 1) * d / h > d / h) {
        //     v = x;
        // } else if (d % h != 0) {
        //     v = x - 1;
        //     v -= (d * v) % h / (d % h);
        // }
        // r[i] = 1LL * a * h - v * d;
        ans += ((x - 1) * d / h) * (x - 2) - floorSum(x - 1, h, d);
        ans += (x - 1) * (a - (x - 1) * d / h);
        // for (int i = 0; i < v; i++) {
        //     std::cerr << (d * (i + 1) / h - d * i / h);
        // }
        // std::cerr << "\n";
        
        auto p = getHull(x - 1, d, h);
        
        int m = p.size();
        while (p.size() > 1 && (p[m - 1][0] - p[m - 2][0]) * (a - p[m - 1][1]) -
                (p[m - 1][1] - p[m - 2][1]) * (x - p[m - 1][0]) >= 0) {
            m--;
            p.pop_back();
        }
        p.push_back({x, a});
        
        for (int j = 0; j < int(p.size()) - 1; j++) {
            b.push_back({p[j + 1][0] - p[j][0], p[j + 1][1] - p[j][1]});
            ans -= p[j][0] * (p[j + 1][1] - p[j][1]);
        }
        // for (auto [x, y] : p) {
        //     std::cerr << x << " " << y << "\n";
        // }
        // std::cerr << "\n";
    }
    std::sort(b.begin(), b.end(), [&](auto a, auto b) {
        return a[0] * b[1] < a[1] * b[0];
    });
    // std::cerr << "ans : " << ans << "\n";
    
    i64 cur = 0;
    for (int i = 0; i < int(b.size()); i++) {
        ans += cur * b[i][1];
        cur += b[i][0];
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}