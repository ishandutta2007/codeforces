#include <bits/stdc++.h>
typedef long long lll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        lll ll, rr;
        cin >> ll >> rr;
        rr++;
        lll ans = rr-ll;
        for(int i = 0; i < 20; i++) {
            lll r = rr, l = ll;
            lll k = 0;
            if((1 << i) & l) {
                l += (1 << i);
            }
            else {
                k -= (l % (1 << i));
            }
            if((1 << i) & r) {
                r += (1 << i);
            }
            else {
                k += (r % (1 << i));
            }
            l /= (1 << i);
            l *= (1 << i);
            r /= (1 << i);
            r *= (1 << i);
            ans = min(ans, k + (r - l)/2);
        }
        cout << ans << '\n';
    }
}