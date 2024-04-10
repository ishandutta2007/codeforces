#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n;
        for(int i = 0; i < n; i++) {
            if(i == 0) cin >> x;
            else cin >> y;
        }
        if(x < y) cout << "YES\n";
        else cout << "NO\n";
    }
}