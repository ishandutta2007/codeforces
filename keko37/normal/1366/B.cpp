#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, x, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x >> m;
        int lo = x, hi = x;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (lo <= a && a <= hi) hi = max(hi, b);
            if (lo <= b && b <= hi) lo = min(lo, a);
            if (a <= lo && hi <= b) lo = a, hi = b;
        }
        cout << hi - lo + 1 << '\n';
    }
    return 0;
}