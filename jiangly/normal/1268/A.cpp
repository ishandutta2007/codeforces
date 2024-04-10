#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t = s.substr(0, k);
    string b;
    while (b.length() < n)
        b += t;
    b.resize(n);
    if (b < s) {
        int i = k - 1;
        while (t[i] == '9') {
            t[i] = '0';
            --i;
        }
        ++t[i];
        b = "";
        while (b.length() < n)
            b += t;
        b.resize(n);
    }
    cout << n << "\n";
    cout << b << "\n";
    return 0;
}