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
        string a, b;
        cin >> a >> b;
        int x = 0, y = 0;
        for(int i = 0; i < a.size(); i++) {
            x += (a.at(i) - '0');
            y += (b.at(i) - '0');
        }
        int ans = n+1;
        if(x+y == n+1) {
            int k = 0;
            for(int i = 0; i < n; i++) {
                if(a.at(i) == b.at(i)) k++;
            }
            ans = min(ans, k);
        }
        if(x == y) {
            int k = 0;
            for(int i = 0; i < n; i++) {
                if(a.at(i) != b.at(i)) k++;
            }
            ans = min(ans, k);
        }
        if(ans == n+1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}