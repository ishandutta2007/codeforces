#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;

LL a[N];
char s[100];
int f[1 << 15];
int main() {
    int n, m;
    scanf("%d%d%*d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') a[i] ^= 1LL << j;
        }
    }
    mt19937 g(time(0));
    uniform_int_distribution<int> u1(0, n - 1);
    LL ans = 0;
    int T = 50;
    while (T--) {
        vector<int> b;
        LL ak = a[u1(g)];
        for (int i = 0; i < m; i++) {
            if (ak >> i & 1) b.push_back(i);
        }
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < b.size(); j++) {
                if (a[i] >> b[j] & 1) {
                    t ^= 1 << j;
                }
            }
            f[t]++;
        }

        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < 1 << b.size(); j++) {
                if ((j >> i & 1) == 0) f[j] += f[j ^ 1 << i];
            }
        }
        int now = 0;
        for (int i = 0; i < 1 << b.size(); i++) {
            if (f[i] * 2 >= n &&
                __builtin_popcount(i) > __builtin_popcount(now))
                now = i;
        }
        if (__builtin_popcount(now) > __builtin_popcountll(ans)) {
            ans = 0;
            for (int i = 0; i < b.size(); i++) {
                if (now >> i & 1) ans ^= 1LL << b[i];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d", ans >> i & 1);
    }
    putchar('\n');
    return 0;
}