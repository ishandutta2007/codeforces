#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p = -1, ans = 0;
        ll sum = 0;
        for(ll i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
            if(sum == (i*i+i)/2) ans++;
        }
        cout << ans << '\n';
    }
}