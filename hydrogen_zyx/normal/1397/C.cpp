#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[500000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl
             << 0 << endl
             << 1 << ' ' << 1 << endl
             << 0 << endl
             << 1 << ' ' << 1 << endl
             << -a[1];
        return 0;
    }
    cout << 1 << ' ' << 1 << endl << -a[1] << endl;
    cout << 2 << ' ' << n << endl;
    for (int i = 2; i <= n; i++) {
        cout << (a[i] % n) * (n - 1) << ' ';
        a[i] += (a[i] % n) * (n - 1);
    }
    cout << endl;
    a[1] = 0;
    cout << 1 << ' ' << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << -a[i] << ' ';
    }
}