#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 1e5 + 10;
lint n, q, A[M], B[M];

struct Seg {
    lint T[M << 2];

    lint init(int lo, int hi, int idx) {
        if (lo == hi) return T[idx] = A[lo];
        return T[idx] = min(init(lo, lo + hi >> 1, idx << 1),
            init(1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
    lint query(int a, int b, int lo = 1, int hi = n, int idx = 1) {
        if (b < lo || a > hi) return 1e18;
        if (a <= lo && hi <= b) return T[idx];
        return min(query(a, b, lo, lo + hi >> 1, idx << 1),
            query(a, b, 1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
} S;
struct Seg2 {
    lint T[M << 2];

    lint init(int lo, int hi, int idx) {
        if (lo == hi) return T[idx] = A[lo];
        return T[idx] = max(init(lo, lo + hi >> 1, idx << 1),
            init(1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
    lint query(int a, int b, int lo = 1, int hi = n, int idx = 1) {
        if (b < lo || a > hi) return -1e18;
        if (a <= lo && hi <= b) return T[idx];
        return max(query(a, b, lo, lo + hi >> 1, idx << 1),
            query(a, b, 1 + (lo + hi >> 1), hi, idx << 1 | 1));
    }
} T;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i]; A[i] -= B[i];
        A[i] += A[i - 1];
    }
    S.init(1, n, 1); T.init(1, n, 1);

    while (q--) {
        int l, r; cin >> l >> r;
        if (A[r] - A[l - 1] != 0) {
            cout << -1 << '\n';
        }
        else if (T.query(l, r) - A[l - 1] > 0) {
            cout << -1 << '\n';
        }
        else {
            lint x = S.query(l, r);
            cout << A[l - 1] - x << '\n';
        }
    }
}