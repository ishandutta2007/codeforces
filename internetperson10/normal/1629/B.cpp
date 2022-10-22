#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l, r, k;
        cin >> l >> r >> k;
        if(l == r) {
            cout << (l == 1 ? "NO\n" : "YES\n");
        }
        else {
            if(!(l%2)) l++;
            if((r%2)) r++;
            cout << ((r-l+1)/2 <= k ? "YES\n" : "NO\n");
        }
    }
}