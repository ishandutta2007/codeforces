#include <bits/stdc++.h>

const int N = 200005;

int T, n, num;
int s[N], a[N];

std::vector<int> d[N];

inline void add(int x, int y) {
    while (x < N) s[x] += y, x += x & -x;
}

inline void add(int x) { add(x, 1); }
inline void dec(int x) { add(x, -1); }

inline int sum(int x) {
    register int ret = 0;
    while (x) ret += s[x], x &= x - 1;
    return ret;
}

inline int insert(std::vector<int> &v) {
    register int i, j;
    i = 0, j = v.size() - 1;
    while (i <= j) {
        if (sum(v[i++]) + sum(v[j--]) != num) return 1;
    }
    for (int &x : v) add(x);
    num += v.size();
    return 0;
}
inline int insert(int x) { return insert(d[x]); }

inline void erase(int x) {
    for (int &x : d[x]) dec(x);
    num -= d[x].size();
}

inline int insert(int l, int r) {
    for (int i = l; i <= r; ++i) {
        if (insert(i)) {
            while (--i >= l) erase(i);
            return 1;
        }
    }
    return 0;
}

inline void erase(int l, int r) {
    for (int i = l; i <= r; ++i) erase(i);
}

inline int solve(int l, int r) {
    if (l == r) return 1;
    int mid = l + r >> 1;
    if (!insert(mid + 1, r)) {
        if (solve(l, mid)) return erase(mid + 1, r), 1;
        erase(mid + 1, r);
    }
    if (!insert(l, mid)) {
        if (solve(mid + 1, r)) return erase(l, mid), 1;
        erase(l, mid);
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], d[a[i]].push_back(i);
        std::cout << (solve(1, n) ? "YES" : "NO") << std::endl;
        for (int i = 1; i <= n; ++i) d[a[i]].pop_back();
    }
    return 0;
}