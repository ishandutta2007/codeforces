#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll sumoffirstk = k*k;

        if (n < sumoffirstk) {
            cout << "NO" << endl;
            continue;
        }
        if (n % 2 == k % 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}