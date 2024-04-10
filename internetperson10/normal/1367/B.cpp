#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, e, o, x, z;
        e = o = x = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> z;
            if(z%2) {
                o++;
                if(i%2) x++;
            }
        }
        if(o != n/2) cout << "-1\n";
        else cout << o-x << '\n';
    }
}