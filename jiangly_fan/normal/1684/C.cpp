#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, ok = 1;
        cin >> n >> m;
        pair<int, int> ans = {-1, -1};
        vector a(n, vector<int>(m));
        for (int i = 0; i < n; i += 1) {
            for (int& aij : a[i]) cin >> aij;
            auto sa = a[i];
            ranges::sort(sa);
            vector<int> p;
            for (int j = 0; j < m; j += 1)
                if (a[i][j] != sa[j]) p.push_back(j);
            if (p.size() > 2)
                ok = 0;
            if (p.size() == 2) {
                auto res = make_pair(p[0], p[1]);
                if (ans.first != -1 and res != ans)
                    ok = 0;
                ans = res;
            }
        }
        if (not ok) cout << "-1\n";
        else {
            if (ans.first == -1) ans.first = ans.second = 0;
            for (auto& ai : a) {
                swap(ai[ans.first], ai[ans.second]);
                if (not ranges::is_sorted(ai))
                    ok = 0;
            }
            if (not ok) cout << "-1\n";
            else cout << ans.first + 1 << " " << ans.second + 1 << "\n";
        }
    }
    return 0;
}