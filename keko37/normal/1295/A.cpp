#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            n /= 2;
            for (int i = 0; i < n; i++) cout << 1;
        } else {
            n = n / 2 - 1;
            cout << 7;
            for (int i = 0; i < n; i++) cout << 1;
        }
        cout << '\n';
    }
    return 0;
}