#include <bits/stdc++.h>

#define Deb std::cout
#define Delin Deb << "[Debug] at Line #" << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl
#define pub push_back

const int N = 100005;
const int I = N << 3;

int n, fplus, fmult, fredu, x, y, z, l, f, c;
int a[N], pl[N], pr[N], pk[N], pf[N], dp[N], red[N], t[N];

std::string s, ans;

inline void solve(int l, int r) {
    // Debug << "solve(" << l << ", " << r << ");" << std::endl;
    while (a[l] == 1 && l < r) ans.pub('1'), ans.pub('+'), ++l;
    if (a[l] == 1) return ans.pub('1'), ans.pub('+'), void(0);
    while (a[r] == 1 && l < r) ++z, --r;
    x = 1;
    for (int i = l; i <= r; ++i) {
        x *= a[i];
        if (x > I) {
            for (int i = l; i < r; ++i) ans.pub(a[i] + '0'), ans.pub('*');
            ans.pub(a[r] + '0'), ans.pub('+');
            while (z) ans.pub('1'), ans.pub('+'), --z;
            return;
        }
    }
    x = 1, pl[c = 1] = l, pk[0] = 1;
    for (int i = l; i <= r; ++i) {
        if (i != l && a[i - 1] == 1 && a[i] != 1) {
            pf[c] = i - pr[c] - 1, pl[++c] = i;
        }
        x *= a[i];
        if (a[i] > 1 && a[i + 1] == 1 || i == r) pr[c] = i, pk[c] = x;
    }
    pf[c] = 0;
    for (int i = 1; i <= c; ++i) {
        dp[i] = 0;
        for (int j = 0; j < i; ++j) {
            if (dp[j] + pk[i] / pk[j] > dp[i]) {
                dp[i] = std::max(dp[i], dp[j] + pk[i] / pk[j]);
                red[i] = j;
            }
        }
        dp[i] += pf[i];
    }
    for (int i = 1; i <= c; ++i) t[i] = 0;
    for (int u = c; u; u = red[u]) t[u] = 1;
    for (int i = 1; i <= c; ++i) {
        // Debug << i << "(" << pl[i] << ", " << pr[i] << ", " << pf[i] << ")" << std::endl;
        for (int j = pl[i]; j < pr[i]; ++j) {
            ans.pub(a[j] + '0'), ans.pub('*');
        }
        ans.pub(a[pr[i]] + '0'), ans.pub(t[i] ? '+' : '*');
        while (pf[i]--) ans.pub('1'), ans.pub(t[i] ? '+' : '*');
    }
    while (z) ans.pub('1'), ans.pub('+'), --z;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::cin >> s;
    for (char c : s) fmult |= c == '*', fplus |= c == '+', fredu |= c == '-';
    if (!fmult) {
        for (int i = 1; i < n; ++i) std::cout << a[i] << (fplus ? '+' : '-');
        return std::cout << a[n] << std::endl, 0;
    } else if (!fplus && !fredu) {
        for (int i = 1; i < n; ++i) std::cout << a[i] << '*';
        return std::cout << a[n] << std::endl, 0;
    } else if (!fplus) {
        for (x = 1; x < n && a[x] && a[x + 1]; ++x) std::cout << a[x] << '*';
        if ((x -= a[1] == 0) && x < n) std::cout << a[x] << '-';
        while (++x < n) std::cout << a[x] << '*';
        return std::cout << a[n] << std::endl, 0;
    }
    ans.pub('0'), ans.pub('+'), l = 1;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i]) continue;
        if (a[i - 1]) solve(l, i - 1);
        ans.pub('0'), ans.pub('+'), l = i + 1;
    }
    // Debug << ans << std::endl;
    std::cout << ans.substr(2, (n << 1) - 1) << std::endl;
    return 0;
}