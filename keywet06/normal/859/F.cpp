#include <bits/stdc++.h>

using int64 = long long;

const int N = 500001;

int qb, qe;
int a[N];

int64 mdq;
int64 f[N], s[N];

std::pair<int64, int64> q[N];

void ad(int64 val, int64 last) {
    val -= mdq, last -= mdq;
    while ((qe > qb) && q[qe - 1].first <= val) --qe;
    q[qe++] = {val, last};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cout << std::fixed << std::setprecision(20);
    memset(q, 0, sizeof(q));
    memset(f, 0, sizeof(f));
    int n;
    int64 c;
    std::cin >> n >> c;
    s[0] = 0;
    for (int i = 1; i <= 2 * n - 1; ++i) std::cin >> a[i];
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        mdq += (a[2 * i - 2] + a[2 * i - 1]);
        ad(f[i - 1] + a[2 * i - 1], a[2 * i - 1]);
        while (q[qb].second + mdq > c) {
            int64 df = q[qb].second + mdq - c;
            q[qb].second -= df, q[qb].first -= df;
            if (qb + 1 == qe || q[qb + 1].first < q[qb].first) break;
            ++qb;
        }
        f[i] = q[qb].first + mdq;
    }
    std::cout << f[n] << "\n";
    return 0;
}