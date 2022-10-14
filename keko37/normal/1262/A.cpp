#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int INF = 1000000007;

int t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = -INF, mn = INF;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            mx = max(mx, a);
            mn = min(mn, b);
        }
        cout << max(mx - mn, 0) << endl;
    }
    return 0;
}