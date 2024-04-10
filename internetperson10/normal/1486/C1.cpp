#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

int ask(int l, int r) {
    int x;
    if(l == r) return -1;
    if(r < l) swap(r, l);
    cout << "? " << l << ' ' << r << endl;
    cin >> x;
    return x;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t, m, n, c, x, y, z, l, r;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> n;
    x = ask(1, n);
    y = ask(1, x); z = ask(x, n);
    if(x == y) {
        l = 1; r = x+1;
        while(l != r-1) {
            int mid = (l+r)/2;
            z = ask(mid, x);
            if(z == x) l = mid;
            else r = mid;
        }
        cout << "! " << l << '\n';
    }
    else {
        l = x-1; r = n;
        while(l != r-1) {
            int mid = (l+r)/2;
            z = ask(x, mid);
            if(z == x) r = mid;
            else l = mid;
        }
        cout << "! " << r << '\n';
    }
}