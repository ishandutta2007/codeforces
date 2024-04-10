#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int k, a, b;
    cin >> k >> a >> b;

    if ((a < k && b % k != 0) || (b < k && a % k != 0)) {
        cout << -1 << endl;
    } else {
        cout << a / k + b / k << endl;
    }

    return 0;
}