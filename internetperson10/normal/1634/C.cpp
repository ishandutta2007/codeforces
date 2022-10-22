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
        if(k == 1) {
            cout << "YES\n";
            for(int i = 1; i <= n; i++) cout << i << '\n';
        }
        else if(n%2 == 0) {
            cout << "YES\n";
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < k; j++) {
                    cout << j*n+i << ' ';
                }
                cout << '\n';
            }
        }
        else {
            cout << "NO\n";
        }
    }
}