#include <bits/stdc++.h>
using namespace std;
constexpr int N = 200000;
int fen[N + 1];
void add(int x) {
    ++x;
    while (x <= N) {
        ++fen[x];
        x += x & -x;
    }
}
int kth(int k) {
    int x = 0;
    for (int i = 18; i >= 0; --i)
        if (x + (1 << i) <= N && fen[x + (1 << i)] <= k) {
            x += (1 << i);
            k -= fen[x];
        }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    vector<vector<pair<int, int>>> qry(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        qry[--x].emplace_back(--y, i);
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) {return a[i] > a[j] || a[i] == a[j] && i < j;});
    vector<int> ans(m);
    for (int i = 0; i < n; ++i) {
        add(b[i]);
        for (auto p : qry[i])
            ans[p.second] = a[kth(p.first)];
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
    return 0;
}