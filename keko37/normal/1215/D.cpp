#include<bits/stdc++.h>

using namespace std;

int n, a, b, x, y;
string s;

int main () {
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (i < n/2) if (s[i] == '?') x++; else a += s[i] - '0';
        if (i >= n/2) if (s[i] == '?') y++; else b += s[i] - '0';
    }
    if (a < b) {
        swap(a, b);
        swap(x, y);
    }
    if (a == b) {
        if (x == y) cout << "Bicarp"; else cout << "Monocarp";
    } else {
        if (x > y) {
            cout << "Monocarp";
        } else {
            if (a - b == 9 * (y - x) / 2) cout << "Bicarp"; else cout << "Monocarp";
        }
    }
    return 0;
}