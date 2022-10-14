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
        if (n == 1) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n-1; i++) cout << 3;
            cout << 4;
            cout << '\n';
        }
    }
    return 0;
}