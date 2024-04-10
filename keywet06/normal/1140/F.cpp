#include <bits/stdc++.h>

using int64 = long long;

const int N = 300005;
const int M = 1 << 33 - __builtin_clz(N - 1);
const int Z = (33 - __builtin_clz(N - 1) << 1) * N;

std::vector<std::pair<int, int> > Seg[M];

inline void Update(int u, int l, int r, int x, int y, std::pair<int, int> v) {
    if (l >= x && r <= y) return Seg[u].push_back(v);
    int Mid = l + r >> 1;
    if (x <= Mid) Update(u << 1, l, Mid, x, y, v);
    if (y > Mid) Update(u << 1 | 1, Mid + 1, r, x, y, v);
}

int Clock;
int Idx[N], Idy[N], F[N], Lenx[N], Leny[N], Size[N];

int64 Sum;
int64 Ans[N];

inline int Find(int x) { return F[x] == x ? x : Find(F[x]); }

inline void GetAns(int u, int l, int r) {
    std::stack<std::tuple<int, int, int> > Stack;
    for (auto [x, y] : Seg[u]) {
        if (Idx[x] && Idy[y]) {
            int fx = Find(Idx[x]), fy = Find(Idy[y]);
            if (fx == fy) continue;
            if (Size[fx] < Size[fy]) std::swap(fx, fy);
            Sum += int64(Lenx[fx]) * Leny[fy] + int64(Leny[fx]) * Lenx[fy];
            Lenx[fx] += Lenx[fy], Leny[fx] += Leny[fy], Size[fx] += Size[fy], F[fy] = fx;
            Stack.emplace(1, fx, fy);
        } else if (Idx[x]) {
            int fx = Find(Idx[x]);
            Stack.emplace(2, fx, y), Idy[y] = fx, Sum += Lenx[fx], ++Leny[fx];
        } else if (Idy[y]) {
            int fy = Find(Idy[y]);
            Stack.emplace(3, x, fy), Idx[x] = fy, Sum += Leny[fy], ++Lenx[fy];
        } else {
            Stack.emplace(4, x, y), ++Clock;
            Idx[x] = Idy[y] = F[Clock] = Clock, ++Sum;
            Lenx[Clock] = Leny[Clock] = Size[Clock] = 1;
        }
    }
    if (l == r) {
        Ans[l] = Sum;
    } else {
        int Mid = l + r >> 1;
        GetAns(u << 1, l, Mid);
        GetAns(u << 1 | 1, Mid + 1, r);
    }
    while (!Stack.empty()) {
        auto [o, x, y] = Stack.top();
        Stack.pop();
        if (o == 1) {
            Lenx[x] -= Lenx[y], Leny[x] -= Leny[y], Size[x] -= Size[y], F[y] = y;
            Sum -= int64(Lenx[x]) * Leny[y] + int64(Leny[x]) * Lenx[y];
        } else if (o == 2) {
            Sum -= Lenx[x], --Leny[x], Idy[y] = 0;
        } else if (o == 3) {
            Sum -= Leny[y], --Lenx[y], Idx[x] = 0;
        } else {
            Idx[x] = Idy[y] = F[Clock] = Lenx[Clock] = Leny[Clock] = Size[Clock] = 0, --Sum, --Clock;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int q;
    std::cin >> q;
    std::map<std::pair<int, int>, int> Map;
    for (int i = 1, x, y; i <= q; ++i) {
        std::cin >> x >> y;
        auto p = std::make_pair(x, y);
        if (Map.count(p)) {
            Update(1, 1, q, Map[p], i - 1, p);
            Map.erase(p);
        } else {
            Map[p] = i;
        }
    }
    for (auto [p, t] : Map) Update(1, 1, q, t, q, p);
    Map.clear();
    GetAns(1, 1, q);
    for (int i = 1; i <= q; ++i) std::cout << Ans[i] << " \n"[i == q];
    return 0;
}