#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, k, sol;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n % 2 == 0) {
            sol = k;
        } else {
            int d = (n - 1) / 2;
            sol = k / d * (d + 1) - 1;
            if (k % d != 0) sol += 1 + k % d;
        }
        sol %= n;
        if (sol == 0) sol = n;
        cout << sol << '\n';
    }
    return 0;
}