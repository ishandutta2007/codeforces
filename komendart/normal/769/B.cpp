#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    int p = 0;
    vector< pair<int, int> > ans;
    for (int i = 1; i < n; ++i) {
        while (p < i && a[p].first == 0) {
            ++p;
        }
        if (p == i) {
            cout << "-1\n";
            return 0;
        }
        --a[p].first;
        ans.push_back({a[p].second, a[i].second});
    }
    cout << ans.size() << '\n';
    for (auto i: ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}