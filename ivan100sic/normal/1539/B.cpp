// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(n + 1);
    for (int i=0; i<n; i++) {
        v[i+1] = v[i] + s[i] - 'a' + 1;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l-1] << '\n';
    }
}