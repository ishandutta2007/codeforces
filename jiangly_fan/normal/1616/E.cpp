#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    for (cin >> q; q; q -= 1) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        auto ss = s;
        ranges::sort(ss);
        if (ss >= t) {
            cout << "-1\n";
            continue;
        }
        vector<deque<int>> p(26);
        for (int i = 0; i < n; i += 1)
            p[s[i] - 'a'].push_back(i);
        vector<int> bit(n);
        auto add = [&](int x, int d) {
            for (x += 1; x <= n; x += x & -x) bit[x - 1] += d;
        };
        auto sum = [&](int x) {
            int res = -1;
            for (x += 1; x; x -= x & -x) res += bit[x - 1];
            return res;
        };
        LL ans = LONG_LONG_MAX, pre = 0;
        for (int i = 0; i < n; i += 1) add(i, 1);
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < t[i] - 'a'; j += 1)
                if (not p[j].empty())
                    ans = min(ans, pre + sum(p[j].front()));
            if (p[t[i] - 'a'].empty()) break;
            pre += sum(p[t[i] - 'a'].front());
            add(p[t[i] - 'a'].front(), -1);
            p[t[i] - 'a'].pop_front();
        }
        cout << ans << "\n";
    }
    return 0;
}