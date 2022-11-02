#include <bits/stdc++.h>

const int B = 2;
const int N = 100005;

bool fl;
bool nw[B], tmp[B];

int n, m;
int mn[B], L1[B], R1[B], a[N];
int L[N][B], R[N][B], pr[N][B];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    mn[0] = mn[1] = n + 1, nw[0] = nw[1] = 1;
    L1[0] = L1[1] = 0, R1[0] = R1[1] = m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> L[i][0] >> R[i][0] >> L[i][1] >> R[i][1];
    }
    for (int i = n; i; --i) {
        nw[0] &= a[i] >= L[i][0] && a[i] <= R[i][0];
        nw[1] &= a[i] >= L[i][1] && a[i] <= R[i][1];
        L1[0] = std::max(L1[0], L[i][1]), R1[0] = std::min(R1[0], R[i][1]);
        L1[1] = std::max(L1[1], L[i][0]), R1[1] = std::min(R1[1], R[i][0]);
        tmp[0] = nw[0] && a[i - 1] >= L1[0] && a[i - 1] <= R1[0];
        tmp[1] = nw[1] && a[i - 1] >= L1[1] && a[i - 1] <= R1[1];
        if (tmp[0]) pr[i][0] = mn[1];
        if (tmp[1]) pr[i][1] = mn[0];
        if (tmp[0]) mn[0] = i, nw[1] = 1, L1[1] = 0, R1[1] = m;
        if (tmp[1]) mn[1] = i, nw[0] = 1, L1[0] = 0, R1[0] = m;
    }
    if (mn[0] > 1 && mn[1] > 1) return std::cout << "NO\n", 0;
    std::cout << "YES\n";
    fl = mn[0] > 1;
    for (int i = 1; i <= n; i = pr[i][fl], fl ^= 1) {
        for (int j = i; j < pr[i][fl]; ++j) std::cout << fl << ' ';
    }
    std::cout << std::endl;
    return 0;
}