#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool add(int x, vector<int> &bs, bool insert = true) {
    int siz = bs.size();
    for (int i = siz - 1; i >= 0; --i) x = min(x, x ^ bs[i]);
    if (!x) return false;
    if (!insert) return true;
    bs.insert(lower_bound(bs.begin(), bs.end(), x), x);
    return true;
}

const int P = 1000000007;
const int N = 100005;

int p2[N], ans[N], a[N];

vector<pair<int, int>> queries[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 0, l, x; i < q; ++i) {
        std::cin >> l >> x;
        queries[l].push_back({x, i});
    }
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) p2[i] = p2[i - 1] * 2 % P;
    vector<int> bs;
    for (int i = 1; i <= n; ++i) {
        add(a[i], bs);
        for (auto q : queries[i]) {
            ans[q.second] = add(q.first, bs, false) ? 0 : p2[i - bs.size()];
        }
    }
    for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
    return 0;
}