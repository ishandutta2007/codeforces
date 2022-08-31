#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> a(m);
    for (int &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    vector<tuple<int, int, int>> trap(k);
    for (int i = 0; i < k; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        trap[i] = {l, r, d};
    }
    sort(trap.begin(), trap.end());
    int l = 0, r = m;
    auto check = [&](int x) {
        int cost = n + 1;
        int rt = 0;
        for (auto tr : trap) {
            int l, r, d;
            tie(l, r, d) = tr;
            if (d <= x)
                continue;
            cost += 2 * max(0, r - max(rt, l));
            rt = max(rt, r);
        }
        return cost <= t;
    };
    while (l < r) {
        int x = (l + r + 1) / 2;
        if (check(a[m - x]))
            l = x;
        else
            r = x - 1;
    }
    cout << l << endl;
    return 0;
}