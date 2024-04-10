#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int N = 500005;
const int I = 222222;

int64 n, m;
int64 a[N], tree[N];

map<int64, int64> mp;

inline int64 lowbit(int64 x) { return x & (-x); }

inline int64 ask(int64 x) {
    if (!x) return 0;
    return tree[x] + ask(x ^ lowbit(x));
}

inline void add(int64 x, int64 y) {
    if (x > 500000) return;
    tree[x] += y, add(x + lowbit(x), y);
}

inline int64 cal(int64 x) {
    int64 sum = 0, rtn = 0;
    memset(tree, 0, sizeof tree);
    add(I, 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= x) {
            ++sum;
        } else {
            --sum;
        }
        rtn += ask(sum + I), add(sum + I, 1);
    }
    return rtn;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << cal(m) - cal(m - 1) << endl;
    return 0;
}