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
        for (int i=0; i<n; i++) {
            cout << string(i, '(');
            for (int j=0; j<n-i; j++) cout << "()";
            cout << string(i, ')') << '\n';
        }
    }
}