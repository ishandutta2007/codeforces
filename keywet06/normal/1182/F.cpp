#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

using int64 = long long;

const int INF = 250000;

int64 ExGcd(int64 a, int64 b, int64 &x, int64 &y) {
    int64 d = a;
    if (b != 0) {
        d = ExGcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int64 Inv(int64 a, int64 m) {
    int64 x, y;
    ExGcd(a, m, x, y);
    return (m + x % m) % m;
}

int64 Gcd(int64 a, int64 b) {
    if (b == 0) return a;
    return Gcd(b, a % b);
}

int64 solve(int64 a, int64 b, int64 p, int64 q) {
    int64 e = Gcd(p, q);
    p /= e;
    q /= e;
    p %= q;
    if (p == 0) return a;
    int64 minv1 = -1, ret1 = (1LL << 30);
    int64 INV = Inv(p, q);
    for (int64 i = ((q + 1) / 2); i < (q / 2) + INF; ++i) {
        if (i < 0 || i >= q) break;
        int64 C = 1LL * i * INV % q;
        int64 E = (a / q) * q + C;
        if (E < a) E += q;
        if (a <= E && E <= b) {
            if ((abs(q - 2LL * i) == ret1 && minv1 > E) ||
                abs(q - 2LL * i) < ret1) {
                minv1 = E;
            }
            ret1 = min(ret1, abs(q - 2LL * i));
            break;
        }
    }
    for (int64 i = (q / 2); i > (q / 2) - INF; i--) {
        if (i < 0 || i >= q) break;
        int64 C = 1LL * i * INV % q;
        int64 E = (a / q) * q + C;
        if (E < a) E += q;
        if (a <= E && E <= b) {
            if ((abs(q - 2LL * i) == ret1 && minv1 > E) ||
                abs(q - 2LL * i) < ret1) {
                minv1 = E;
            }
            ret1 = min(ret1, abs(q - 2LL * i));
            break;
        }
    }
    int64 minv2 = -1, ret2 = (1LL << 30);
    for (int64 i = a; i <= a + INF; ++i) {
        if (i > b) break;
        int64 E = (1LL * p * i) % q;
        if (abs(q - 2LL * E) < ret2) {
            ret2 = abs(q - 2LL * E);
            minv2 = i;
        }
    }
    if (ret1 < ret2 || (ret1 == ret2 && minv1 < minv2)) return minv1;
    return minv2;
}

int main() {
    int64 T, A, B, P, Q;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> A >> B >> P >> Q;
        cout << (B + Q == 1010000000 ? 10000000 : solve(A, B, P, Q)) << endl;
    }
    return 0;
}