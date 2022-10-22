#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        multiset<ll> s;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ll g;
            cin >> g;
            s.insert(g);
        }
        while(s.size()) {
            auto g = s.begin();
            ll num = *g;
            s.erase(g);
            if(s.count(num*k) == 0) {
                ans++;
                s.insert(num*k);
            }
            g = s.find(num*k);
            s.erase(g);
        }
        cout << ans << '\n';
    }
}