#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        while (not mp.empty()) {
            vector<int> p;
            for (auto it = mp.begin(); it != mp.end();) {
                p.push_back(it->second.back());
                it->second.pop_back();
                if (it->second.empty()) it = mp.erase(it);
                else it = next(it);
            }
            for (int i = 0; i < p.size(); i += 1)
                b[p[i]] = a[p[(i + 1) % p.size()]];
        }
        for (int bi : b) cout << bi << " ";
        cout << "\n";
    }
    return 0;
}