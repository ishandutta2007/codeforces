#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;
const long long INF = 100000000000000000LL;
const int MOD = 1000000007;

int n, h, w;
char str[N];
long long a[N], b[N];
long long l[N], r[N];

void get(long long *a, int w, char L, char R) {
    int cnt = 0;
    for (int i = 0; i <= w + 1; i++) l[i] = r[i] = INF;
    for (long long i = 1; i <= n; i++) {
        if (str[i] == L) cnt--;
        if (str[i] == R) cnt++;
        int v;
        if (cnt < 0) {
            v = min(w, -cnt);
            r[v] = min(r[v], i);
        }
        else if (cnt > 0) {
            v = max(1, w - cnt + 1);
            l[v] = min(l[v], i);
        }
    }
    for (int i = 1; i <= w; i++) l[i] = min(l[i], l[i - 1]);
    for (int i = w; i >= 1; i--) r[i] = min(r[i], r[i + 1]);
    if (cnt > 0) {
        for (int i = w; i >= 1; i--) {
            if (i - cnt >= 1) l[i - cnt] = min(l[i - cnt], l[i] + n);
        }
    } else {
        for (int i = 1; i <= w; i++) {
            if (i - cnt <= w) r[i - cnt] = min(r[i - cnt], r[i] + n);
        }
    }
    for (int i = 1; i <= w; i++) a[i] = min(l[i], r[i]);
}

int main() {
    scanf("%d%d%d", &n, &h, &w);
    scanf("%s", str + 1);
    get(a, w, 'L', 'R');
    get(b, h, 'U', 'D');
    sort(a + 1, a + w + 1);
    sort(b + 1, b + h + 1);
    if (a[w] == INF && b[h] == INF) printf("-1\n");
    else {
        int ans = 0;
        int sum = 0;
        int u = 0;
        for (int i = 1; i <= w; i++) {
            while (u + 1 <= h && b[u + 1] < a[i])
                sum = (sum + b[++u]) % MOD;
            ans = (ans + sum) % MOD;
            ans = (ans + a[i] * (h - u) % MOD) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}