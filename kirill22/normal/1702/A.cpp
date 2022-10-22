#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = 1;
        while (x * 1ll * 10 <= n) {
            x *= 10;
        }
        cout << n - x << '\n';
    }
}