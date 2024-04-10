#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int N = 305;

map<int, int> dp[2];
map<int, int>::iterator it;

int n, l[N], c[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &l[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    int now = 0, pre = 1;
    dp[now].clear();
    dp[now][0] = 0;
    for (int i = 0; i < n; i++) {
        swap(now, pre);
        dp[now].clear();
        for (it = dp[pre].begin(); it != dp[pre].end(); it++) {
            int u = it->first, w = it->second;
            int v = gcd(u, l[i]), vw = w + c[i];
            if (!dp[now].count(u)) dp[now][u] = w;
            else dp[now][u] = min(dp[now][u], w);
            if (!dp[now].count(v)) dp[now][v] = vw;
            else dp[now][v] = min(dp[now][v], vw);
        }
    }
    if (dp[now].count(1)) printf("%d\n", dp[now][1]);
    else printf("-1\n");
    return 0;
}