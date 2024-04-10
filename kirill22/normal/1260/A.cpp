#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int x = b / a;
        int z = b % a;
        cout << (x + 1) * (x + 1) * z + x * x * (a - z) << endl;
    }
}