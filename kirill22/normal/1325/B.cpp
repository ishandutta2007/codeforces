#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int x = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) x++;
        }
        cout << x << endl;
    }
}