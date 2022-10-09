// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (n % 2) {
            n--;
            s.pop_back();
        }

        int z = find(begin(s), end(s), '0') - begin(s);
        if (z < n) {
            if (z < n/2) {
                cout << z+1 << ' ' << n << ' ' << z+2 << ' ' << n << '\n';
            } else {
                cout << "1 " << z+1 << " 1 " << z << '\n';
            }
        } else {
            cout << "1 " << n << " 1 " << n/2 << '\n';
        }
    }
}