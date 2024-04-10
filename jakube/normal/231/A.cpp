#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        res += (a + b + c) >= 2;
    }
    cout << res << endl;

    return 0;
}