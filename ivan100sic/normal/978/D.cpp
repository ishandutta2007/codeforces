#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[1000005];

ll proveri(ll p, ll q) {
    ll s = 0;

    for (int i=0; i<n; i++) {
        ll z = p + i*q;
        ll r = abs(z - a[i]);
        if (r > 1)
            return 123123123123123123ll;
        s += r;
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    ll lr = 123123123123123123ll;
    ll hr = -lr;

    if (n <= 2) {
        cout << "0\n";
        return 0;
    }

    for (int i=0; i<n-1; i++) {
        ll r = a[i+1] - a[i];
        lr = min(lr, r);
        hr = max(hr, r);
    }

    if (hr - lr >= 5) {
        cout << "-1\n";
        return 0;
    }

    ll sol = 123123123123123123ll;

    for (ll r=lr-2; r<=hr; r++) {
        for (ll prvi=a[0]-1; prvi<=a[0]+1; prvi++) {
            sol = min(sol, proveri(prvi, r));
        }
    }

    if (sol == 123123123123123123ll)
        sol = -1;

    cout << sol << '\n';

}