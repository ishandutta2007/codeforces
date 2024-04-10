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
        string s;
        cin >> s;
        int a = count(begin(s), end(s), 'A');
        int b = count(begin(s), end(s), 'B');
        int c = count(begin(s), end(s), 'C');

        cout << (a + c == b ? "YES\n" : "NO\n");
    }
}