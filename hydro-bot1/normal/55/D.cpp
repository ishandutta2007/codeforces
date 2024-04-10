// Hydro submission #61891d0a07d7abb3c5820e61@1636375818224
#include <bits/stdc++.h>
using namespace std;
#define N 20
#define p 2520

int a[p + 10], tot = 0;
long long l, r, f[N][p + 1][50];
vector<int> v;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return !b ? a : a / gcd(a, b) * b;
}

long long dfs(int k, int d, int l, int op) {
    if (!k) return (d % l == 0);
    if (!op && f[k][d][a[l]]) return f[k][d][a[l]];
    int Mx = op ? v[k] : 9; long long res = 0;
    for (int i = 0; i <= Mx; i ++) {
        res += dfs(k - 1, (d * 10 + i) % p, lcm(l, i), op & (i == Mx));
    }
    if (!op) f[k][d][a[l]] = res;
    return res;
}

long long Do(long long x, long long t = 0) {
    v.clear(), v.push_back(-1), t = x;
    while (t) v.push_back(t % 10), t /= 10;
    return dfs(v.size() - 1, 0, 1, 1);
}

int main() {
    for (int i = 1; i <= p; i ++) {
        if (p % i == 0) a[i] = ++ tot;
    }

    int T; scanf("%d", &T);
    while (T --) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", Do(r) - Do(l - 1));
    }
    return 0;
}