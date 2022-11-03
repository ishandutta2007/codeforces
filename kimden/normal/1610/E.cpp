// HI
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

map<int, int> mp;
vector<int> v;
vector<int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        v.clear();
        cnt.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++mp[x];
        }
        for (auto &p: mp) {
            v.push_back(p.first);
            cnt.push_back(p.second);
        }
        int m = v.size();
        int ans = cnt[m - 1];
        for (int i = 0; i + 1 < m; ++i) {
            int cur = cnt[i] + 1;
            int start = v[i];
            int last = v[i + 1];
            int idx = i + 1;
            while (1) {
                idx = lower_bound(v.begin() + idx, v.end(), last - start + last) - v.begin();
                if (idx >= m) {
                    break;
                }
                last = v[idx];
                ++cur;
            }
            ans = max(ans, cur);
        }
        cout << n - ans << '\n';
    }



}