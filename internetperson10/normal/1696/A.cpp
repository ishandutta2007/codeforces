#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, z;
        cin >> n >> z;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans = max(ans, (x | z));
        }
        cout << ans << '\n';
    }
}