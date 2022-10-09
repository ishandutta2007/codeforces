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
        int j = find_if(begin(s), end(s), [](char c) { return c != '?'; }) - begin(s);

        if (j == n) {
            for (int i=0; i<n; i++) {
                cout << (i % 2 ? 'B' : 'R');
            }
            cout << '\n';
            continue;
        }

        for (int i=j+1; i<n; i++) {
            if (s[i] == '?') {
                s[i] = s[i-1] ^ 'R' ^ 'B';
            }
        }

        for (int i=j-1; i>=0; i--) {
            if (s[i] == '?') {
                s[i] = s[i+1] ^ 'R' ^ 'B';
            }
        }

        cout << s << '\n';
    }
}