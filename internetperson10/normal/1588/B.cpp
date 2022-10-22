#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll ask(ll l, ll r) {
    cout << "? " << l+1 << ' ' << r << endl;
    ll g;
    cin >> g;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll tot = ask(0, n);
        int l = 0, r = n;
        while(l != r - 1) {
            int mid = (l + r + 1) / 2;
            if(ask(0, mid) == tot) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        ll k = r;
        ll j = k - (tot - ask(0, l));
        ll i = j - 1 - (ask(0, j-1) - ask(0, j-2)); 
        cout << "! " << i << ' ' << j << ' ' << k << endl;
    }
}