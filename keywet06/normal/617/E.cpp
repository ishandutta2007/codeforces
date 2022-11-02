#include <bits/stdc++.h>

const int S = 330;
const int N = 1 << 20;

struct Query {
    int id, l, r;
    bool operator<(const Query o) const {
        if (l / S != o.l / S) return l < o.l;
        if (l / S % 2 == 0) return r < o.r;
        return r > o.r;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> freq(N, 0);
    std::vector<Query> Qr(m);
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] ^= a[i - 1];
    std::vector<long long> ans(m, 0);
    long long tot = 0;
    for (int i = 0; i < m; i++) Qr[i].id = i, std::cin >> Qr[i].l >> Qr[i].r, --Qr[i].l, ++Qr[i].r;
    std::sort(Qr.begin(), Qr.end());
    int l = 0, r = 0;
    auto Add = [&](int x) { tot += freq[x ^ k], ++freq[x]; };
    auto Rem = [&](int x) { --freq[x], tot -= freq[x ^ k]; };
    for (auto q : Qr) {
        while (l > q.l) Add(a[--l]);
        while (r < q.r) Add(a[r++]);
        while (l < q.l) Rem(a[l++]);
        while (r > q.r) Rem(a[--r]);
        ans[q.id] = tot;
    }
    for (int i = 0; i < m; i++) std::cout << ans[i] << " \n"[i + 1 == m];
    return 0;
}