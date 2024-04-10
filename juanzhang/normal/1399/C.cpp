#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

namespace IO {
    #define gc getchar()
    template <typename t>
    inline void read(t& x) {
        x = 0; bool f = 1; char ch;
        for (ch = gc; ch < '0' || '9' < ch; ch = gc) if (ch == '-') f ^= 1;
        for (; '0' <= ch && ch <= '9'; ch = gc) x = (x << 3) + (x << 1) + (ch ^ 48);
        x = f ? x : -x;
    }
    #undef gc
}

const int MAXN = 1000 + 10;

int arr[MAXN], cnt[MAXN], ans = 0;

void solve() {
    int n; IO::read(n); ans = 0;
    memset(cnt, 0, sizeof cnt);
    rep(i, 1, n) IO::read(arr[i]), cnt[arr[i]]++;
    rep(i, 1, n << 1) {
        int cur = 0;
        rep(j, 1, i >> 1) cur += (j << 1) == i ? cnt[j] >> 1 : min(cnt[j], cnt[i - j]);
        if (ans < cur) ans = cur;
    }
    printf("%d\n", ans);
}

int main() {
    int t; IO::read(t);
    while (t--) solve();
    return 0;
}