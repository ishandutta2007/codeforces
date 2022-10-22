#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            if(s[j-1] == '0') {
                if(s2[j-1] == '0') ans += i;
                s2[j-1] = '1';
            }
            else break;
        }
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