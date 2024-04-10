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
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int g = gcd(d, n);
        int sol = 0;
        for (int i=0; i<g; i++) {
            int cnt = 0, streak = 0, maxstreak = 0;
            for (int j=0; j<2*n/g; j++) {
                int idx = (i + 1ll*j*d) % n;
                if (a[idx]) {
                    cnt++;
                    streak++;
                    maxstreak = max(maxstreak, streak);
                } else {
                    streak = 0;
                }
            }

            if (cnt == 2*n / g) {
                sol = -1;
                break;
            } else {
                sol = max(sol, maxstreak);
            }
        }

        cout << sol << "\n";
    }
}