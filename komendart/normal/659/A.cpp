#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    cout << ((a + b - 1) % n + n) % n + 1 << endl;
}