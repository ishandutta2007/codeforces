#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, z;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        map<int, vector<int>> c;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    c[j].push_back(i);
                    break;
                }
            }
        }
        cout << (int) c.size() << endl;
        int k = 0;
        for (auto el : c) {
            k++;
            for (auto x : el.second) ans[x] = k;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}