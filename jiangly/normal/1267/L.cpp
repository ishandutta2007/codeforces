#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans(n);
    int same = 0, cnt = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = same; j < k; ++j)
            ans[j] += s[cnt++];
        while (ans[same].back() != ans[k - 1].back())
            ++same;
    }
    for (int i = 0; i < n; ++i) {
        while (ans[i].length() < l)
            ans[i] += s[cnt++];
        cout << ans[i] << "\n";
    }
    return 0;
}