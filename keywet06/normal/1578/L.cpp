#include <bits/stdc++.h>

template <typename _Tp>
inline _Tp &Mid(_Tp &x, _Tp y) {
    return x < y ? x : (x = y);
}

template <typename _Tp>
inline _Tp &Mad(_Tp &x, _Tp y) {
    return x > y ? x : (x = y);
}

using int64 = long long;

template <typename _Tp, typename _Vec = std::vector<_Tp>,
          typename _Comp = std::greater<_Tp> >
using PriorityQueue = std::priority_queue<_Tp, _Vec, _Comp>;

const int N = 100005;

struct Node {
    int id;
    Node() : id(0) {}
    Node(int x) : id(x) {}
};

int n, m, k, p;

int64 Max, l, r, mid, u;
int64 h[N], s[N], t[N], a[N];

inline bool operator>(Node x, Node y) { return t[x.id] > t[y.id]; }

inline bool Check(int64 Height) {
    PriorityQueue<Node> q;
    for (int i = 1; i <= n; ++i) {
        if (Height - a[i] * m >= h[i]) continue;
        t[i] = (s[i] = Height) / a[i] + 1;
        q.emplace(i);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (q.empty()) return true;
            u = q.top().id, q.pop();
            if (t[u] <= i) return false;
            if ((s[u] += p) - a[u] * m >= h[u]) continue;
            t[u] = s[u] / a[u] + 1;
            q.emplace(u);
        }
    }
    return q.empty();
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i] >> a[i];
        Mad(Max, h[i] + a[i] * m);
    }
    l = 0, r = Max;
    while (l < r) {
        mid = l + r >> 1;
        if (Check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
    return 0;
}