#include <bits/stdc++.h>

using namespace std;

const int N_ = 100000;
const int N = 100005;

using int64 = long long;

int ntp[N], phi[N], p[N], pn;

int64 dp[19][N];
int64 G[N];

vector<int> d[N];
void init(int n) {
    ntp[1] = true, phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!ntp[i]) p[++pn] = i, phi[i] = i - 1;
        for (int j = 1; j <= pn && p[j] * i <= n; ++j) {
            ntp[p[j] * i] = true;
            if (i % p[j] == 0) {
                phi[p[j] * i] = phi[i] * p[j];
                break;
            }
            phi[p[j] * i] = phi[i] * (p[j] - 1);
        }
    }
    G[1] = 1;
    for (int i = 2; i <= n; ++i) {
        G[i] = G[i - 1] + phi[i];
    }
}

int64 now;

inline int Get(int x, int lim) {
    int tot = 0;
    for (auto t : d[x]) {
        if (t >= lim) {
            tot += phi[x / t];
        }
    }
    return tot;
}

int64 calc(int ql, int qr) {
    static int l = 1, r = 0;
    while (r < qr) ++r, now += Get(r, l);
    while (l > ql) --l, now += G[r / l];
    while (l < ql) now -= G[r / l], ++l;
    while (r > qr) now -= Get(r, l), --r;
    return now;
}

void Solve(int l, int r, int ql, int qr, int64 *f, int64 *g) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    int p = ql;
    for (int i = ql; i <= min(mid - 1, qr); ++i) {
        int64 tp = g[i] + calc(i + 1, mid);
        if (tp < f[mid]) {
            f[mid] = tp, p = i;
        }
    }
    Solve(l, mid - 1, ql, p, f, g);
    Solve(mid + 1, r, p, qr, f, g);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(N_);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int j = 1; j <= N_; ++j) {
        for (int i = j; i <= N_; i += j) {
            d[i].push_back(j);
        }
    }
    for (int i = 1; i <= 18; ++i) {
        Solve(1, N_, 0, N_ - 1, dp[i], dp[i - 1]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int n, k;
        cin >> n >> k;
        if (k > 18) {
            cout << n << '\n';
        } else {
            cout << dp[k][n] << '\n';
        }
    }
    return 0;
}