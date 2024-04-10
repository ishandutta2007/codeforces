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
        map<int, int> ma;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ma[tot + x] = ma[tot] + 1;
            tot += x;
        }
        int ans = 0;
        for(auto p : ma) {
            int g = p.first;
            if(g > tot/2) break;
            if(ma[tot - g]) ans = max(ans, ma[g] + n - ma[tot - g]);
        }
        cout << ans << '\n';
    }
}