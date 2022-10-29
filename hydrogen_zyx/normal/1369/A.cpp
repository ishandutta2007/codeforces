#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
}