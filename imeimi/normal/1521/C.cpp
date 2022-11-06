#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int R[] = { 0, 2, 5, 3, 4, 1 };
int q(int t, int i, int j, int x) {
    #ifdef imeimi
    if (t == 1) return max(min(x, R[i]), min(x + 1, R[j]));
    if (t == 2) return min(max(x, R[i]), max(x + 1, R[j]));
    #endif
    printf("? %d %d %d %d\n", t, i, j, x);
    fflush(stdout);
    scanf("%d", &t);
    return t;
}

int n, P[10005];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) P[i] = 0;
    {
        int s = 1, e = n;
        while (s < e) {
            int m = (s + e) / 2;
            if (q(2, 1, 2, m) > m) s = m + 1;
            else e = m;
        }
        P[1] = s;
    }
    if (P[1] - 1 > n - P[1]) {
        for (int i = 2; i <= n; ++i) {
            int x = q(2, i, 1, 1);
            if (x < P[1]) P[i] = x;
        }
        int j = 0;
        for (int i = 2; i <= n; ++i) {
            if (P[i] == 1) j = i;
        }
        for (int i = 2; i <= n; ++i) {
            if (P[i] == 0) P[i] = q(1, j, i, n - 1);
        }
    }
    else {
        for (int i = 2; i <= n; ++i) {
            int x = q(1, 1, i, n - 1);
            if (x > P[1]) P[i] = x;
        }
        int j = 0;
        for (int i = 2; i <= n; ++i) {
            if (P[i] == n) j = i;
        }
        for (int i = 2; i <= n; ++i) {
            if (P[i] == 0) P[i] = q(2, i, j, 1);
        }
    }
    printf("!");
    for (int i = 1; i <= n; ++i) printf(" %d", P[i]);
    printf("\n");
    fflush(stdout);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}