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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        reverse(a.begin(), a.end());
        vector<int> f(n);
        long long cnt = 0;
        for (auto x : a) {
            for (int i = x - 1; i >= 0; i = (i & (i + 1)) - 1) {
                cnt += f[i];
            }
            for (int i = x; i < n; i |= (i + 1)) {
                f[i]++;
            }
        }
        set<int> b(a.begin(), a.end());
        if ((int) b.size() != n || cnt % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}