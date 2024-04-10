#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "2\n";
        if (n == 2) {
            cout << "1 2\n";
        } else {
            cout << n - 2 << " " << n << '\n';
            cout << n - 1 << " " << n - 1 << '\n';
            for (int i = n - 3; i >= 1; i--) {
                cout << i << " " << i + 2 << '\n';
            }
        }
    }
    return 0;
}