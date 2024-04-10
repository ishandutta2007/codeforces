#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, m, n;
        cin >> x >> m >> n;
        while(m--) {
            int a = x/2 + 10;
            if(a > x) break;
            x = a; 
        }
        x -= 10*n;
        if(x > 0) cout << "NO\n";
        else cout << "YES\n";
    }
}