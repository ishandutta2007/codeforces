// Hydro submission #619371f601410992b6879581@1637052918854
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 3e5 + 5, B = 20, S = N * B;
int n, m, lc[S], rc[S], val[S], cnt, a[N];

void insert(int x) {
    int p = 0;
    for (int i = B - 1; i >= 0; i--) {
        if (x >> i & 1)
            p = rc[p] ? rc[p] : rc[p] = ++cnt;
        else
            p = lc[p] ? lc[p] : lc[p] = ++cnt;
        val[p]++;
    }
}

int query(int x) {
    int p = 0, ans = 0;
    for (int i = B - 1; i >= 0; i--)
        if (x >> i & 1) {
            if (val[rc[p]] == 1 << i)
                ans |= 1 << i, p = lc[p];
            else
                p = rc[p];
        } else {
            if (val[lc[p]] == 1 << i)
                ans |= 1 << i, p = rc[p];
            else
                p = lc[p];
        }
    return ans;
}

template <class T>
void read(T &ret) {
    ret = 0;
    char ch = getchar();
    bool found = false;
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') found = true, ch = getchar();
    while (isdigit(ch)) ret = ret * 10 + ch - '0', ch = getchar();
    if (found) ret = -ret;
}

template <class T, class... Args>
void read(T &ret, Args &...rest) {
    read(ret), read(rest...);
}

int main() {
    read(n, m);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1), n = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 1; i <= n; i++) insert(a[i]);
    int cur = 0, x;
    while (m--) read(x), cur ^= x, printf("%d\n", query(cur));
    return 0;
}