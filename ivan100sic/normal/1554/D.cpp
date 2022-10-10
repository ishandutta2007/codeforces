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
        if (n <= 26) {
            for (int i=0; i<n; i++) {
                cout << char('a' + i);
            }
        } else {
            int k = (n-5)/4;
            stack<char> sep;
            for (int i=0; i<n-(4*k+2); i++) {
                sep.push('c' + i);
            }

            cout << string(k, 'a');
            cout << sep.top();
            sep.pop();

            cout << string(k, 'b');
            cout << sep.top();
            sep.pop();

            cout << string(k+1, 'a');
            cout << sep.top();
            sep.pop();

            cout << string(k+1, 'b');
            while (sep.size()) {
                cout << sep.top();
                sep.pop();
            }
        }
        cout << '\n';
    }
}