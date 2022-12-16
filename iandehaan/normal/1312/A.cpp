#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}