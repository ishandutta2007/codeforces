#include <bits/stdc++.h>
using namespace std;

template <typename T>
T floor_div(T a, long long b) {
    return (a < 0 ? a - (b - 1) : a) / b;
}

template <typename T>
T ceil_div(T a, long long b) {
    return (a >= 0 ? a + (b - 1) : a) / b;
}

template <typename T>
class LinearDiophantine {
public:
    static T extended_gcd(T a, T b, T& x, T& y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        long long d = extended_gcd(b % a, a, y, x);
        x -= b / a * y;
        return d;
    }

    static bool solve(T a, T b, T c, T& x, T& y, T& g) {
        if (a == 0) {
            if (b == 0) {
                x = y = 0;
                g = 1;
                return c == 0;
            } else {
                x = 0;
                y = c / b;
                g = abs(b);
                return c % b == 0;
            }
        } else {
            if (b == 0) {
                x = c / a;
                y = 0;
                g = abs(b);
                return c % a == 0;
            } else {
                g = extended_gcd(a, b, x, y);
                T dx = c / a;
                c %= a;
                T dy = c / b;
                c %= b;
                x = dx + multiply_mod(x, c / g, b);
                y = dy + multiply_mod(y, c / g, a);
                g = abs(g);
                return c % g == 0;
            }
        }
    }

    static void smallest_non_negative_x(T a, T b, T& x, T& y, T g) {
        long long k;
        if (b >= 0)
           k = ceil_div(-x, b / g);
        else
           k = floor_div(x, -b / g);
        x += k * (b / g);
        y -= k * (a / g);
    }

    static void smallest_non_negative_y(T a, T b, T& x, T& y, T g) {
        long long k;
        if (a >= 0)
           k = ceil_div(-y, a / g);
        else
           k = floor_div(y, -a / g);
        x += k * (b / g);
        y -= k * (a / g);
    }

    static T multiply_mod(T x, T y, T m) {
        int sign = (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
        x = abs(x) % m;
        y = abs(y) % m;
        T res = 0;
        while (y) {
            if (y & 1)
                res = (res + x) % m;
            x = (x << 1) % m;
            y >>= 1;
        }
        return sign * res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;
    
    if (vx == 0) {
        if (x != 0 && x != n) {
            cout << -1 << '\n';
        } else if (vy == 1) {
            cout << x << " " << m << '\n';
        } else {
            cout << x << " " << 0 << '\n';
        }
        return 0;
    }

    if (vy == 0) {
        if (y != 0 && y != m) {
            cout << -1 << '\n';
        } else if (vx == 1) {
            cout << n << " " << y << '\n';
        } else {
            cout << 0 << " " << y << '\n';
        }
        return 0;
    }

    int t1 = vx > 0 ? n - x : x;
    int t2 = vy > 0 ? m - y : y;
    // solve t1 + a * n = t2 + b * m
    // a * n - b * m = t2 - t1
    int a, b, g;
    if (!LinearDiophantine<int>::solve(n, -m, t2 - t1, a, b, g)) {
        cout << -1 << '\n';
    } else {
        LinearDiophantine<int>::smallest_non_negative_x(n, -m, a, b, g);
        if (b < 0)
            LinearDiophantine<int>::smallest_non_negative_y(n, -m, a, b, g);
        assert(a >= 0 && b >= 0);

        if (vx > 0)
            a++;
        if (vy > 0)
            b++;
        cout << (a % 2 ? n : 0) << " " << (b % 2 ? m : 0) << '\n';
    }
}