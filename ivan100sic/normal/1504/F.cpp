// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int e[200005], dir[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        if (max(x, y) <= n || min(x, y) > n) {
            cout << "-1\n";
            return 0;
        }

        e[min(x, y)] = max(x, y);
        dir[min(x, y)] = x < y;
    }

    // can?
    {
        int m1 = 2*n+5, m2 = 2*n+5;
        for (int i=1; i<=n; i++) {
            if (e[i] > m2) {
                cout << "-1\n";
                return 0;
            } else if (e[i] > m1) {
                m2 = min(m2, e[i]);
            } else {
                m1 = min(m1, e[i]);
            }
        }
    }
    
    int mn=2*n+5, sol=0, fwd=0, bck=0;
    for (int i=1; i<=n; i++) {
        int x = e[i];
        ((x > mn) ^ dir[i] ? fwd : bck)++;
        mn = min(x, mn);
        if (mn + i == 2*n+1) {
            sol += min(fwd, bck);
            fwd = bck = 0;
        }
    }

    cout << sol << '\n';
}