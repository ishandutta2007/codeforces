#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    bitset<2000> flip[2001];
    for (int i = 0; i < 2000; ++i) {
        flip[i + 1] = flip[i];
        flip[i + 1][i] = 1;
    }
    int n, m, q;
    cin >> n >> m >> q;
    vector<bitset<2000>> rows(n);
    set<pair<int, int>> s;
    set<int> ans;
    auto check = [&](int a, int b) {
        if (a == -1)
            return;
        ans.erase(a);
        if (b == -1)
            return;
        // cerr << "check(" << a << ", " << b << ")" << endl;
        // cerr << (rows[a] | rows[b]) << ", " << rows[b] << endl;
        if ((rows[a] | rows[b]) != rows[b])
            ans.insert(a);
    };
    auto findAnswer = [&]() {
        if (ans.empty()) {
            puts("-1");
            return;
        }
        int x = *ans.begin();
        int y = next(s.find({rows[x].count(), x}))->second;
        if (x > y)
            swap(x, y);
        auto b = rows[x] & ~rows[y];
        int l = b._Find_first();
        b = ~rows[x] & rows[y];
        int r = b._Find_first();
        if (l > r)
            swap(l, r);
        printf("%d %d %d %d\n", x + 1, l + 1, y + 1, r + 1);
    };
    s.emplace(-1, -1);
    s.emplace(m + 1, -1);
    for (int i = 0; i < n; ++i) {
        s.emplace(0, i);
    }
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        --x;
        --l;
        auto it = s.find({rows[x].count(), x});
        auto p = prev(it), n = next(it);
        s.erase(it);
        check(p->second, n->second);
        rows[x] ^= flip[r] >> l << l;
        it = s.emplace(rows[x].count(), x).first;
        p = prev(it);
        n = next(it);
        check(p->second, x);
        check(x, n->second);
        findAnswer();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}