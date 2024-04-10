#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > k && i < k) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}