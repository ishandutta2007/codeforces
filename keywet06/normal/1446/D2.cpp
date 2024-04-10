#include <bits/stdc++.h>

const int N = 200054;

int n, B, ans, mode;
int a[N], count[N];
int buc[2 * N];
int cur[N];

inline void up(int &x, const int y) { x < y ? x = y : 0; }

void solve(int x) {
    int i, p = n;
    memset(buc, -1, (2 * n + 1) << 2), buc[p] = 0;
    for (i = 0; i < n; ++i) {
        p += (a[i] == x) - (a[i] == mode);
        if (~buc[p]) {
            up(ans, i - buc[p] + 1);
        } else {
            buc[p] = i + 1;
        }
    }
}

void check(int L) {
    int i, j = 0, Z = 0;
    memset(cur, 0, (n + 1) << 2);
    for (i = 0; i < n && j < n; ++i) {
        for (; j < n; ++j)
            if (++cur[a[j]] > L) {
                --cur[a[j]];
                break;
            } else
                Z += cur[a[j]] == L;
        if (Z > 1) up(ans, j - i);
        Z -= cur[a[i]]-- == L;
    }
}

int main() {
    int i;
    bool multi = false;
    std::ios::sync_with_stdio(false), std::cin.tie(NULL);
    std::cin >> n, B = sqrt(n);
    for (i = 0; i < n; ++i) std::cin >> a[i], ++count[a[i]];
    for (i = 1; i <= n; ++i) {
        if (count[i] > count[mode]) {
            mode = i, multi = false;
        } else if (count[i] == count[mode]) {
            multi = true;
        }
    }
    if (multi) return std::cout << n << '\n', 0;
    for (i = 1; i <= n; ++i) {
        if (i != mode && count[i] >= B) solve(i);
    }
    for (i = 1; i <= B; ++i) check(i);
    std::cout << ans << '\n';
    return 0;
}