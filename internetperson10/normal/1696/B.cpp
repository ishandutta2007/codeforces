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
        int ans = 0;
        int x = 0;
        for(int i = 0; i < n; i++) {
            int y;
            cin >> y;
            if(y == 0) {
                x = 0;
            }
            else {
                if(x == 0) ans++;
                x = 1;
            }
        }
        cout << min(ans, 2) << '\n';
    }
}