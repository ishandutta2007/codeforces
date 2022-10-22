#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k+1 == n) {
            if(n == 4) cout << "-1\n";
            else {
                cout << 3 << ' ' << 1 << '\n';
                cout << n-2 << ' ' << 2 << '\n';
                cout << n-3 << ' ' << n-4 << '\n';
                cout << 0 << ' ' << n-1 << '\n';
                for(int i = 4; i < n/2; i++) {
                    cout << i << ' ' << n-1-i << '\n';
                }
            }
        }
        else {
            cout << 0 << ' ' << n-1-k << '\n';
            if(k != 0) cout << k << ' ' << n-1 << '\n';
            for(int i = 0; i < n/2; i++) {
                if(i != 0 && i != k && i != n-1-k) {
                    cout << i << ' ' << n-1-i << '\n';
                }
            }
        }
    }
}