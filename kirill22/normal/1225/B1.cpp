#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> b;
        int ans = 0;
        for (int i = 0; i < d; i++) {
            b[a[i]]++;
        }
        ans = b.size();
        for (int i = d; i < n; i++) {
            b[a[i - d]]--;
            b[a[i]]++;
            if (b[a[i - d]] == 0) {
                b.erase(a[i - d]);
            }
            ans = min(ans, (int) b.size());
        }
        cout << ans << endl;
    }
}