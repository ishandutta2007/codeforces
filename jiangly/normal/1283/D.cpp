#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    set<int> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        x.insert(s[i]);
        y.insert(s[i]);
    }
    int d = 0;
    long long ans = 0;
    while (y.size() < n + m) {
        ++d;
        vector<int> e;
        for (int i : x) {
            bool ok = false;
            if (y.size() < n + m && y.find(i - d) == y.end()) {
                ans += d;
                y.insert(i - d);
                ok = true;
            }
            if (y.size() < n + m && y.find(i + d) == y.end()) {
                ans += d;
                y.insert(i + d);
                ok = true;
            }
            if (!ok)
                e.push_back(i);
        }
        for (int i : e)
            x.erase(i);
    }
    for (int i : s)
        y.erase(i);
    cout << ans << "\n";
    for (int i : y)
        cout << i << " \n"[i == *y.rbegin()];
    return 0;
}