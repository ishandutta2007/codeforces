#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ma = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            a[i] -= b[i];
            ma = max(ma, a[i]);
        }
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(ma != a[i] && (b[i])) ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}