#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> ma;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ma[x]++;
        }
        int mod = 0;
        for(auto p : ma) {
            mod = max(mod, p.second);
        }
        int ans = 0;
        while(mod < n) {
            ans++;
            ans += min(n, mod * 2) - mod;
            mod *= 2;
        }
        cout << ans << '\n';
        ma.clear();
    }
}