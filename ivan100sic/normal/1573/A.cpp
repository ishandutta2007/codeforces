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
        int x = 0;
        for (char c : s) {
            if (c != '0') {
                x += c - '0' + 1;
            }
        }

        if (s.back() != '0') {
            x--;
        }
        cout << x << '\n';
    }
}