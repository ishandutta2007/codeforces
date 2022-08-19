#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> fa(26, -1);
    vector<bool> exist(26);
    auto find = [&](int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    };
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        exist[s[0] - 'a'] = true;
        for (int j = 1; j < s.length(); ++j) {
            int x = find(s[0] - 'a');
            int y = find(s[j] - 'a');
            if (x != y)
                fa[y] = x;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        if (exist[i] && fa[i] == -1)
            ++ans;
    cout << ans << "\n";
    return 0;
}