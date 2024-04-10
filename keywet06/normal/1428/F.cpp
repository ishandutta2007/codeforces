#include <bits/stdc++.h>

using int64 = long long;

const int N = 2000005;

char x;

int n;
int s[N];

int64 t, c;
int64 h[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> x, s[i] = (x - '0');
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 0 && (t += c, 1)) continue;
        int l = i, r = i;
        while (r < n && s[r + 1] == 1) r++;
        for (int x = 1; x <= (r - l + 1); ++x) {
            c += (l - 1 + x) - h[x], t += c, h[x] = r - x + 1;
        }
        i = r;
    }
    std::cout << t << '\n';
    return 0;
}