#include <bits/stdc++.h>
const int N = 400005;
int n, m, top;
int pre[N], suf[N], a[N], ans[N], res[N], sta[N], cov[N];
std::vector<std::pair<int, int> > vc[N];
std::pair<int, int> d[N], tmp[N];
void solve(int l, int r) {
    if (l == r) {
        return;
    }
    const int mid = (l + r) / 2;
    solve(l, mid), solve(mid + 1, r);
    for (int i = mid, nw = 0, it = r; i >= l; --i) {
        while (it > mid && d[i].first < d[it].first) {
            nw = std::max(nw, suf[d[it--].second]);
        }
        cov[d[i].second + 1] = pre[d[i].second] + nw;
    }
    for (int i = l + 1; i <= mid; ++i) cov[i] = std::max(cov[i], cov[i - 1]);
    for (int i = l; i <= mid; ++i) res[i] = std::max(res[i], cov[i]);
    for (int i = l; i <= mid + 1; ++i) cov[i] = 0;
    for (int i = mid + 1, nw = 0, it = l; i <= r; ++i) {
        while (it <= mid && d[i].first > d[it].first) {
            nw = std::max(nw, pre[d[it++].second]);
        }
        cov[d[i].second - 1] = suf[d[i].second] + nw;
    }
    for (int i = r - 1; i > mid; --i) cov[i] = std::max(cov[i], cov[i + 1]);
    for (int i = mid + 1; i <= r; ++i) res[i] = std::max(res[i], cov[i]);
    for (int i = mid; i <= r; ++i) cov[i] = 0;
    int itL = l, itR = mid + 1, it = l;
    while (itL <= mid && itR <= r)
        if (d[itL] < d[itR]) {
            tmp[it++] = d[itL++];
        } else {
            tmp[it++] = d[itR++];
        }
    while (itL <= mid) tmp[it++] = d[itL++];
    while (itR <= r) tmp[it++] = d[itR++];
    for (int i = l; i <= r; ++i) d[i] = tmp[i];
}
int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int p, x;
        std::cin >> p >> x;
        vc[p].emplace_back(x, i);
        ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        res[i] = top;
        for (auto it : vc[i]) {
            int v = it.first, id = it.second;
            int len = std::lower_bound(sta, sta + top + 1, v) - sta - 1;
            ans[id] += len;
        }
        int t = std::lower_bound(sta, sta + top + 1, a[i]) - sta;
        if (t > top) {
            sta[++top] = a[i];
        } else {
            sta[t] = std::min(sta[t], a[i]);
        }
        pre[i] = t;
    }
    sta[top = 0] = 1e9 + 7;
    for (int i = n; i; --i) {
        res[i] = std::max(res[i], top);
        for (auto it : vc[i]) {
            int v = it.first, id = it.second;
            int len =
                std::lower_bound(sta, sta + top + 1, v, std::greater<int>()) -
                sta - 1;
            ans[id] += len;
        }
        int t =
            std::lower_bound(sta, sta + top + 1, a[i], std::greater<int>()) -
            sta;
        if (t > top) {
            sta[++top] = a[i];
        } else {
            sta[t] = std::max(sta[t], a[i]);
        }
        suf[i] = t;
    }
    for (int i = 1; i <= n; ++i) d[i] = std::make_pair(a[i], i);
    solve(1, n);
    for (int i = 1; i <= n; ++i) {
        for (auto it : vc[i]) ans[it.second] = std::max(ans[it.second], res[i]);
    }
    for (int i = 1; i <= m; ++i) std::cout << ans[i] << '\n';
    return 0;
}