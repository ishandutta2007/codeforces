#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> d;
        int sol = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            while (d- i >= 0 && x > 0) d -= i, x--, sol++;
        }
        cout << sol << '\n';
    }
    return 0;
}