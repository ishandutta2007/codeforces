#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
       string a, b, c;
       cin >> a >> b >> c;
       bool f = true;
       for (int i = 0; i < a.size(); i++) {
            int k = 0;
            if (a[i] == c[i]) k++;
            if (b[i] == c[i]) k++;
            if (k == 0) f = false;
       }
       if (f) cout << "YES" << endl;
       else cout << "NO" << endl;
    }
}