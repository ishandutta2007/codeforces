#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0;
        cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        int la = 2;
        for(int i = 0; i < n; i++) {
            if(s[0][i] == s[1][i]) {
                if(s[0][i] == '1') {
                    if(la == 0) {
                        ans++;
                        la = 2;
                    }
                    else {
                        la = 1;
                    }
                }
                else {
                    if(la == 1) {
                        ans += 2;
                        la = 2;
                    }
                    else {
                        ans += 1;
                        la = 0;
                    }
                }
            }
            else {
                la = 2;
                ans += 2;
            }
        }
        cout << ans << '\n';
    }
}