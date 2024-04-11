#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<string> str(n);
    vector< pair<int, int> > pos;
    int size = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        int len; cin >> len;
        for (int j = 0; j < len; ++j) {
            int k; cin >> k;
            pos.push_back({k, i});
            size = max(size, k + (int) str[i].size());
        }
    }
    sort(pos.begin(), pos.end());
    int right = 0;
    string ans(size, 'a');
    for (auto p: pos) {
        int x = p.first;
        const string &s = str[p.second];
        for (int i = max(x, right); i < x + (int) s.size(); ++i) {
            ans[i] = s[i - x];
        }
        right = max(right, x + (int) s.size());
    }
    cout << ans.substr(1, size - 1) << '\n';
}