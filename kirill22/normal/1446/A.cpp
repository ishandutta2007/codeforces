#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> a(n), id;
        int pos = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= s) {
                id.push_back(i);
                if (a[i] >= (s + 1) / 2) {
                    pos = i;
                }
            }
        }
        vector<int> ans;
        if (pos != -1) {
            ans = {pos};
        } else {
            long long f = 0;
            for (auto i : id) {
                if (f + a[i] <= s) {
                    f += a[i];
                    ans.push_back(i);
                }
            }
            if (f < (s + 1) / 2) {
                ans.clear();
            }
        }
        if ((int) ans.size()) {
            cout << (int) ans.size() << '\n';
            for (auto i : ans) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}