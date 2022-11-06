#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << '\n';
    } else if (n % 2 == 0) {
        int a = 2;
        int b = n * n / 2;
        cout << (b - a) / 2 << ' ' << (b + a) / 2 << '\n';
    } else {
        int a = 1;
        int b = n * n;
        cout << (b - a) / 2 << ' ' << (b + a) / 2 << '\n';
    }
}