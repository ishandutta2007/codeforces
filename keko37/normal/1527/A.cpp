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
            cout << 0 << '\n';
        } else {
            int pot = 1;
            while (pot <= n) pot *= 2; pot /= 2;
            cout << pot - 1 << '\n';
        }
    }
    return 0;
}