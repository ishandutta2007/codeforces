#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int64 P = int64(1e9) + 7;

int64 add(int64 x, int64 y) {
    x += y;
    if (x >= P) return x - P;
    return x;
}
int64 sub(int64 x, int64 y) {
    x -= y;
    if (x < 0) return x + P;
    return x;
}
int64 mult(int64 x, int64 y) { return (x * y) % P; }

const int N = int(1e6) + 7;
int64 f[N], rf[N];
int64 pw1[N], pw2[N];
int n, m;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    rf[0] = rf[1] = 1;
    for (int64 x = 2; x < N; x++) rf[x] = sub(0, mult(P / x, rf[P % x]));
    for (int i = 2; i < N; i++) rf[i] = mult(rf[i - 1], rf[i]);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = mult(f[i - 1], i);
    scanf("%d%d", &n, &m);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = mult(pw1[i - 1], n);
        pw2[i] = mult(pw2[i - 1], m);
    }
    int64 ans = 0;
    for (int k = 1; k < n - 1 && k <= m; k++) {
        int64 cur = k + 1;
        cur = mult(cur, pw1[n - k - 2]);
        cur = mult(cur, f[n - 2]);
        cur = mult(cur, rf[n - k - 1]);
        cur = mult(cur, f[m - 1]);
        cur = mult(cur, rf[k - 1]);
        cur = mult(cur, rf[m - k]);
        cur = mult(cur, pw2[n - 1 - k]);
        ans = add(ans, cur);
    }
    if (n - 1 <= m) {
        int64 cur = f[n - 2];
        cur = mult(cur, f[m - 1]);
        cur = mult(cur, rf[n - 2]);
        cur = mult(cur, rf[m - n + 1]);
        ans = add(ans, cur);
    }
    std::cout << ans << std::endl;
    return 0;
}