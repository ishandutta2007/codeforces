#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0;
        cin >> n;
        n /= 2;
        for(int i = 1; i <= n; i++) ans += (1 << i);
        cout << ans << '\n';
    }
}