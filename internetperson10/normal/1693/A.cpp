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
        ll s = 0, x = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(s == 0 && x != 0 && i != 0) {
                ok = false;
            }
            if(x < s) {
                ok = false;
            }
            s -= x;
        }
        if(s != 0) {
            ok = false;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}