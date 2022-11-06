#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n > 30) {
        cout << m << endl;
    } else {
        cout << m % (1 << n) << endl;
    }
}