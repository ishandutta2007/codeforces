#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << (n - 1) / 2 << '\n';
        }
        else cout << n / 2<< '\n';
    }
}