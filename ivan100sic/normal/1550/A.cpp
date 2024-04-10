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
        int s, c = 0;
        cin >> s;
        for (int x=1; s>0; x+=2) {
            s -= x;
            c++;
        }
        cout << c << '\n';
    }
}