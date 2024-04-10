// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int rs(string a, string b) {
    for (int i=0, k=0, s=0; i<(int)a.size(); i++) {
        if (a[i] == b[k]) {
            k++;
            if (k == 2) {
                return s;
            }
        } else {
            s++;
        }
    }

    return 123123123;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(begin(s), end(s));
        int z = min({
            rs(s, "52"),
            rs(s, "05"),
            rs(s, "57"),
            rs(s, "00"),
        });

        cout << z << '\n';
    }
}