#include<bits/stdc++.h>

using namespace std;

int t, n, x, a, b;

int main () {
    cin >> t;
    while (t--) {
        cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        cout << abs(a - b) + min(x, a - 1 + n - b) << '\n';
    }
    return 0;
}