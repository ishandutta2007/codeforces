#include <bits/stdc++.h>

using int64 = long long;
const int P = 1000000007;
const int N = 220000;
const int C = 230;
const int Q = 87;
const int Z = 350;
const int K = 20;

using namespace std;

bool vis[N];

int n, m, cnt;
int a[N], ivs[N], prime[N], loc[N], lm[N], rm[N], range[N], base[N];
int power[Q][K];
int pre[C][N];
int itv[Z][Z];

void get_p() {
    for (int i = 2; i < N; ++i) {
        if (!ivs[i]) {
            prime[++cnt] = i;
            ivs[i] = i;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; ++j) {
            ivs[prime[j] * i] = prime[j];
            if (prime[j] == ivs[i]) break;
        }
    }
}

void prepare_first() {
    int sum = 0;
    for (int i = 1; i < Q; ++i) {
        range[i] = (log(200000) / log(prime[i]));
        base[i] = sum;
        sum += range[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < C; ++j) pre[j][i] = pre[j][i - 1];
        for (int j = 1; j < Q; ++j) {
            int cnt = 0;
            while (!(a[i] % prime[j])) {
                cnt++;
                a[i] /= prime[j];
            }
            if (cnt) pre[base[j] + cnt - 1][i] = i;
        }
    }
    for (int i = 1; i < Q; ++i) {
        int tmp = 1;
        for (int j = 1; j < K; ++j) {
            tmp = 1ll * tmp * prime[i] % P;
            power[i][j] = tmp;
        }
    }
}

void prepare_second() {
    for (int i = 1; i <= n; ++i) {
        lm[i] = loc[a[i]];
        loc[a[i]] = i;
    }
    for (int i = 1; i < N; ++i) loc[i] = n + 1;
    for (int i = n; i >= 1; i--) {
        rm[i] = loc[a[i]];
        loc[a[i]] = i;
    }
    for (int i = 1; i <= n; i += Z) {
        memset(vis, 0, sizeof(vis));
        int tmp = 1;
        for (int j = i; j <= n; ++j) {
            if (!vis[a[j]]) {
                vis[a[j]] = 1;
                tmp = 1ll * tmp * a[j] % P;
            }
            if (!(j % Z) || j == n) {
                itv[i / Z][(j - 1) / Z] = tmp;
            }
        }
    }
}

int main() {
    get_p();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    prepare_first();
    prepare_second();
    scanf("%d", &m);
    int lst = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = (lst + x) % n + 1;
        y = (lst + y) % n + 1;
        if (x > y) swap(x, y);
        lst = 1;
        for (int i = 1; i < Q; ++i) {
            for (int j = base[i] + range[i] - 1; j >= base[i]; j--) {
                if (pre[j][y] >= x) {
                    lst = 1ll * lst * power[i][j - base[i] + 1] % P;
                    break;
                }
            }
        }
        if (y - x + 1 <= 2 * Z) {
            for (int i = x; i <= y; ++i)
                if (lm[i] < x) lst = 1ll * lst * a[i] % P;
        } else {
            int L = (x - 1) / Z + 1, R = (y - 1) / Z - 1;
            lst = 1ll * lst * itv[L][R] % P;
            for (int i = x; i <= L * Z; ++i)
                if (rm[i] > (R + 1) * Z) lst = 1ll * lst * a[i] % P;
            for (int i = (R + 1) * Z + 1; i <= y; ++i)
                if (lm[i] < x) lst = 1ll * lst * a[i] % P;
        }
        printf("%d\n", lst);
    }
    return 0;
}