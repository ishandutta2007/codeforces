// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        int h = 0;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        while (n > 0) {
            int c = w;
            h++;
            for (int x=(1<<29); x; x>>=1) {
                while (x <= c && mp[x] > 0) {
                    c -= x;
                    mp[x]--;
                    n--;
                }
            }
        }

        cout << h << '\n';        
    }
}