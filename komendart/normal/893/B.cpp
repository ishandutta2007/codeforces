#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for (int k = 20; k >= 0; --k) {
        int d = ((1LL << k) - 1) << (k - 1);
        if (n % d == 0) {
            cout << d << '\n';
            return 0;
        }
    }
    
}