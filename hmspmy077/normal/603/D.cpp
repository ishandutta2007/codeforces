#include <algorithm>
#include <cstdio>
#include <vector>

const int N = 2000;

int gcd(int a, int b) {
    return b ? a : gcd(b, a % b);
}

// struct Fraction {
//     Fraction(long long p, long long q) {
//         int g = gcd(p, q);
//         p /= g;
//         q /= g;
//         if (q < 0) {
//             p *= -1;
//             q *= -1;
//         }
//         this->p = p;
//         this->q = q;
//     }
//
//     long long p, q;
// };
//
// Fraction operator - (const Fraction &a, const Fraction &b) {
//     return Fraction((long long))
// }

typedef double Double;

Double Fraction(Double a, Double b) {
    return a / b;
}

const double EPS = 1e-11;

int signum(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    Point() {}

    Point(Double x, Double y) : x(x), y(y) {
    }

    double slope() const {
        if (signum(x) == 0) {
            return 1e100;
        }
        return y / x;
    }

    bool zero() const {
        return signum(x) == 0 && signum(y) == 0;
    }

    Double x, y;
};

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

int binom(int n) {
    return n * (n - 1) / 2;
}

int n, a[N], b[N], c[N];
Point p[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", a + i, b + i, c + i);
        int s = a[i] * a[i] + b[i] * b[i];
        p[i] = Point(Fraction(a[i] * c[i], s), Fraction(b[i] * c[i], s));
    }
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        std::vector<double> slopes;
        bool has_zero = false;
        for (int j = i + 1; j < n; ++ j) {
            Point q = p[j] - p[i];
            if (q.zero()) {
                has_zero = true;
            } else {
                slopes.push_back(q.slope());
            }
        }
        std::sort(slopes.begin(), slopes.end());
        for (int j = 0; j < (int)slopes.size(); ) {
            int k = j;
            while (k < (int)slopes.size() && signum(slopes[j] - slopes[k]) == 0) {
                k ++;
            }
            result += binom(k - j);
            if (has_zero) {
                result += k - j;
            }
            j = k;
        }
    }
    printf("%d\n", result);
    return 0;
}