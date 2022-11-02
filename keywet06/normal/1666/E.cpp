#include <bits/stdc++.h>

int l, n, a[100005];
int Pos[100005], pot[100005];

bool Posm(int len) {
    Pos[n] = l;
    for (int i = n - 1; i >= 0; i--) {
        Pos[i] = std::min(a[i], Pos[i + 1] - len);
        if (Pos[i] < (i == 0 ? 0 : a[i - 1])) return false;
    }
    return true;
}

bool Posx(int len) {
    pot[n] = l;
    for (int i = n - 1; i >= 0; i--) {
        pot[i] = std::max(i == 0 ? 0 : a[i - 1], pot[i + 1] - len);
        if (pot[i] > a[i]) return false;
    }
    return pot[0] == 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> l >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int ml = 0, mr = l, xl = 0, xr = l;
    while (ml < mr) {
        int Mid = (ml + mr + 1) >> 1;
        Posm(Mid) ? ml = Mid : mr = Mid - 1;
    }
    Posm(ml);
    while (xl < xr) {
        int Mid = (xl + xr) >> 1;
        Posx(Mid) ? xr = Mid : xl = Mid + 1;
    }
    Posx(xl);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int nc = cur + ml;
        nc = std::min(nc, Pos[i + 1]);
        nc = std::max(nc, pot[i + 1]);
        printf("%d %d\n", cur, nc);
        cur = nc;
    }
    return 0;
}