#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int x = n - m;
        m++;
        int z = x / m;
        cout << (n * (n + 1)) / 2 - (((x % m) * (z + 1) * (z + 2)) / 2 + ((m - x % m) * (z * (z + 1))) / 2) << endl;
    }
}