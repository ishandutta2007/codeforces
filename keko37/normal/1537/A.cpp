#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            sum += x;
        }
        if (sum == n) {
            cout << 0 << '\n';
        } else if (sum > n) {
            cout << sum - n << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}