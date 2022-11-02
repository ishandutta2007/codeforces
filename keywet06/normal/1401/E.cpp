#include <bits/stdc++.h>

using int64 = long long;

const int M = 100005;
const int N = 1000001;
const int R = N + 10;
const int T = R << 2;

int val;
int y[M], lx[M], rx[M];
int seg[T];

int64 ans = 1;

std::vector<int> add[R], del[R];

std::vector<std::pair<int, std::pair<int, int> > > q;

void addSeg(int p, int id = 1, int s = 0, int e = N) {
    seg[id] += val;
    if (e - s == 1) return;
    int mid = (s + e) / 2, lc = id * 2, rc = lc + 1;
    p < mid ? addSeg(p, lc, s, mid) : addSeg(p, rc, mid, e);
    return;
}
int get(int l, int r, int id = 1, int s = 0, int e = N) {
    if (e <= l || r <= s) return 0;
    if (l <= s && e <= r) return seg[id];
    int mid = (s + e) / 2, lc = id * 2, rc = lc + 1;
    return get(l, r, lc, s, mid) + get(l, r, rc, mid, e);
}
void Fine(int plc) {
    for (auto x : add[plc]) val = 1, addSeg(x);
    for (auto x : del[plc]) val = -1, addSeg(x);
    return;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> y[i] >> lx[i] >> rx[i];
        add[lx[i]].push_back(y[i]), del[rx[i] + 1].push_back(y[i]);
        ans += (lx[i] == 0 && rx[i] == 1000 * 1000);
    }
    for (int i = 0; i < m; i++) {
        int xx, ll, rr;
        std::cin >> xx >> ll >> rr;
        q.push_back({xx, {ll, rr}});
        ans += (ll == 0 && rr == 1000 * 1000);
    }
    std::sort(q.begin(), q.end());
    int rn = 0;
    for (auto p : q) {
        int xx = p.first, ll = p.second.first, rr = p.second.second + 1;
        while (rn != xx + 1) Fine(rn), rn++;
        int rtr = get(ll, rr);
        ans += rtr;
    }
    std::cout << ans << std::endl;
    return 0;
}