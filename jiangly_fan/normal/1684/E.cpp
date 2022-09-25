#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            mp[a] += 1;
        }
        int L = 0, R = n;
        while (L < R) {
            int M = (L + R + 1) / 2, ch = 0;
            for (int i = 0; i < M; i += 1)
                ch += not mp.contains(i);
            if (ch <= k) L = M;
            else R = M - 1;
        }
        vector<int> v;
        for (auto [x, y] : mp)
            if (x > L)
                v.push_back(y);
        int ans = v.size();
        ranges::sort(v);
        for (int i = 0; i < v.size(); i += 1) {
            if (k >= v[i]) {
                k -= v[i];
                ans -= 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}