#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, n, r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> r;
        if (n <= r) {
            cout << n * (n - 1) / 2 + 1 << '\n';
        } else {
            cout << r * (r + 1) / 2 << '\n';
        }
    }
    return 0;
}