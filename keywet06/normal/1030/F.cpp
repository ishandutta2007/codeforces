#include <bits/stdc++.h>

typedef long long int64;

const int64 N = 2e5 + 5;
const int64 P = 1e9 + 7;

int64 add(int64 x) { return (x >= P) ? x - P : x; }
int64 sub(int64 x) { return (x < 0) ? x + P : x; }
void Add(int64 &x, int64 y) { x = add(x + y); }
void Sub(int64 &x, int64 y) { x = sub(x - y); }

int64 S[N], A[N], W[N];
int64 n, q;

void add(int64 x, int64 v) {
    for (int64 i = x; i < N; i += i & -i) S[i] += v;
}

int64 Sum(int64 x) {
    int64 res = 0;
    for (int64 i = x; i; i -= i & -i) res += S[i];
    return res;
}

namespace Bit {

int64 S[N];
void add(int64 x, int64 v) {
    for (int64 i = x; i < N; i += i & -i) Add(S[i], v);
}
int64 Sum(int64 x) {
    int64 res = 0;
    for (int64 i = x; i; i -= i & -i) Add(res, S[i]);
    return res;
}

}  // namespace Bit

int64 calc(int64 l, int64 r, int64 x) {
    if (x < l || x > r) return 0LL;
    int64 ans = 0;
    Add(ans, 1LL * sub(A[x] - x) * ((Sum(x - 1) - Sum(l - 1)) % P) % P);
    Sub(ans, sub(Bit::Sum(x - 1) - Bit::Sum(l - 1)));
    Add(ans, sub(Bit::Sum(r) - Bit::Sum(x)));
    Sub(ans, 1LL * sub(A[x] - x) * ((Sum(r) - Sum(x)) % P) % P);
    return ans;
}

int main() {
    std::cin >> n >> q;
    for (int64 i = 1; i <= n; ++i) std::cin >> A[i];
    for (int64 i = 1; i <= n; ++i) std::cin >> W[i], add(i, W[i]), Bit::add(i, 1LL * W[i] * sub(A[i] - i) % P);
    int64 x, y, l, r;
    while (q--) {
        std::cin >> x >> y;
        if (x < 0) {
            x = -x;
            add(x, -W[x]);
            Bit::add(x, 1LL * W[x] * sub(x - A[x]) % P);
            W[x] = y;
            add(x, W[x]);
            Bit::add(x, 1LL * W[x] * sub(A[x] - x) % P);
        } else {
            l = x, r = y;
            if (l == r) {
                puts("0");
                continue;
            }
            int64 All = Sum(r) - Sum(l - 1);
            int64 L = l, R = r, res = R;
            while (L <= R) {
                int64 mid = (L + R) >> 1;
                if (Sum(mid) - Sum(l - 1) >= All / 2 + (All & 1)) {
                    res = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            std::cout << calc(l, r, res) << '\n';
        }
    }
    return 0;
}