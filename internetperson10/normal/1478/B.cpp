#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

bool arr[10][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, w, x, y, z, q, d;
    ll m, n, a, b, c, k, ans=0;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            for(int k = 0; 10*k+i*j < 90; k++) {
                arr[i][10*k + i*j] = true;
            }
        }
    }
    cin >> t;
    while(t--) {
        cin >> q >> d;
        while(q--) {
            cin >> x;
            if(x >= 10*d) cout << "YES\n";
            else if(arr[d][x]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}