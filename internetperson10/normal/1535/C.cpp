#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll ans = 0;
        int odd = -1, even = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s.at(i) == '?') {
                ans += (i - min(odd, even));
            }
            else if((s.at(i) + i)%2) {
                ans += (i - even);
                odd = i;
            }
            else {
                ans += (i - odd);
                even = i;
            }
        }
        cout << ans << '\n';
    }
}