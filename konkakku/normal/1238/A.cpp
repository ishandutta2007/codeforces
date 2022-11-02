#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    long long x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x == y + 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}