#include <bits/stdc++.h>

typedef long long int64;
typedef std::pair<int64, int64> Pair;

const int N = 200005;

std::map<int64, int> id1, id2;
std::map<Pair, int64> Map;

int64 a[N], b[N], sum1[N], sum2[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    int sz1 = 0, sz2 = 0;
    for (int i = 1; i <= n; ++i) {
        int64 x, y, z;
        std::cin >> x >> y >> z;
        if (!id1.count(x)) id1[x] = ++sz1, a[sz1] = x;
        if (!id2.count(y)) id2[y] = ++sz2, b[sz2] = y;
        Map[Pair(x, y)] = z, sum1[id1[x]] += z, sum2[id2[y]] += z;
    }
    if ((int64)sz1 * sz2 != n) {
        puts("0");
        return 0;
    }
    int64 d1 = 0, d2 = 0;
    for (int i = 1; i <= sz1; ++i) d1 = std::__gcd(d1, sum1[i]);
    for (int i = 1; i <= sz2; ++i) d2 = std::__gcd(d2, sum2[i]);
    for (int i = 1; i <= sz1; ++i) sum1[i] /= d1;
    for (int i = 1; i <= sz2; ++i) sum2[i] /= d2;
    int64 t = -1;
    for (int i = 1; i <= sz1; ++i) {
        for (int j = 1; j <= sz2; ++j) {
            int64 v = Map[Pair(a[i], b[j])];
            if (v % sum1[i] != 0) {
                puts("0");
                return 0;
            }
            v /= sum1[i];
            if (v % sum2[j] != 0) {
                puts("0");
                return 0;
            }
            v /= sum2[j];
            if (t != -1 && v != t) {
                puts("0");
                return 0;
            }
            t = v;
        }
    }
    int ans = 0;
    for (int64 i = 1; i * i <= t; ++i) {
        if (t % i == 0) {
            ++ans;
            if (i * i != t) ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}