#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll a, ll b) {
    ll mmin = 10, mmax = 0;
    for (int i = 1; i < b; i++) {
        mmin = 10;
        mmax = 0;
        ll mid = a;
        if (a == 0) {
            mmin = mmax = 0;
        }
        while (mid) {
            mmin = min(mmin, mid % 10);
            mmax = max(mmax, mid % 10);
            mid /= 10;
        }
        if (mmin == 0)
            break;
        else
            a += mmax * mmin;
    }
    return a;
}
int main() {
    ll t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << fun(a, b) << endl;
    }
}