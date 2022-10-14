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
        int mx = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                mx = n / i;
                break;
            }
        }
        cout << mx << " " << (n / mx - 1) * mx << '\n';
    }
    return 0;
}