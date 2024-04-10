#include<bits/stdc++.h>

using namespace std;

int q;
map <int, int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        mp.clear();
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (int i=1; i<=1024; i*=2) {
            mp[2*i] += mp[i] / 2;
        }
        if (mp[2048]) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}