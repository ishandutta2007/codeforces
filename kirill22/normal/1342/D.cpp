#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(-x);
    }
    vector<int> c(m);
    for (int i = 0; i < m; i++) cin >> c[i];
    vector<vector<int>> ans;
    while (a.size() > 0) {
        vector<int> tmp;
        int sz = 0;
        while (true) {
            if (c[0] <= sz) break;
            int l = 0, r = m;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (c[mid] >= sz + 1) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            l++;
            //cout << l << " ";
            auto it = a.lower_bound(-l);
            if (it == a.end()) break;
            int p = *it;
            a.erase(a.find(p));
            tmp.push_back(-p);
            //cout << p << " ";
            sz++;
        }//cout << endl;
        ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        for (auto x : ans[i]) cout << x << " ";
        cout << '\n';
    }
}