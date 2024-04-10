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
        cin >> n;
        n *= 2;
        int a[2] = {0, 0};
        while (n--) {
            int x;
            cin >> x;
            a[x % 2]++;
        }
        cout << (a[0] == a[1] ? "Yes\n": "No\n");
    }
}