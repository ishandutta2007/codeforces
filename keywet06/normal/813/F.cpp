#include <bits/stdc++.h>

using Pair = std::pair<int, int>;

const int N = 1e5 + 10;

int n, q;

std::vector<Pair> vec[N << 2];

std::map<Pair, int> mp;

void ins(int v, int b, int e, int l, int r, int x, int y) {
    if (l <= b && e <= r) {
        vec[v].push_back({x, y});
        return;
    }
    if (r <= b || e <= l) return;
    int mid = b + e >> 1;
    ins(v << 1, b, mid, l, r, x, y);
    ins(v << 1 ^ 1, mid, e, l, r, x, y);
}

bool fail;

int par[N], sz[N], cp[N];

int getPar(int v) { return par[v] == v ? v : getPar(par[v]); }
int getCol(int v) { return par[v] == v ? 0 : cp[v] ^ getCol(par[v]); }

int cc;

Pair sec[N * 5];

void rev() {
    auto z = sec[--cc];
    if (z.first == -1) return;
    if (z.first == -2) {
        fail = 0;
        return;
    }
    int px = z.first, py = z.second;
    par[px] = px;
    sz[py] -= sz[px];
    cp[px] = 0;
}

void go(int v, int b, int e) {
    for (auto z : vec[v]) {
        int x = z.first, y = z.second;
        if (fail) {
            sec[cc++] = {-1, -1};
        } else {
            int px = getPar(x), py = getPar(y);
            if (px ^ py) {
                if (sz[px] > sz[py]) std::swap(x, y), std::swap(px, py);
                par[px] = py;
                sz[py] += sz[px];
                if (getCol(x) == getCol(y)) cp[px] = 1;
                sec[cc++] = {px, py};
            } else {
                if (getCol(x) != getCol(y)) {
                    sec[cc++] = {-1, -1};
                } else {
                    sec[cc++] = {-2, -2}, fail = 1;
                }
            }
        }
    }

    if (e - b == 1) {
        if (fail) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    } else {
        int mid = b + e >> 1;
        go(v << 1, b, mid);
        go(v << 1 ^ 1, mid, e);
    }
    for (int i = 0; i < vec[v].size(); ++i) rev();
}

int xx[N], yy[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> xx[i] >> yy[i], --xx[i], --yy[i];
        if (mp.count({xx[i], yy[i]})) {
            ins(1, 0, q, mp[{xx[i], yy[i]}], i, xx[i], yy[i]);
            mp.erase({xx[i], yy[i]});
        } else {
            mp[{xx[i], yy[i]}] = i;
        }
    }
    for (auto x : mp) ins(1, 0, q, x.second, q, x.first.first, x.first.second);
    std::iota(par, par + n, 0);
    std::fill(sz, sz + n, 1);
    go(1, 0, q);
    return 0;
}