#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        ll numb[n];
        ll sm = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) numb[i] = max((ll)0, a[i]-b[i-1]);
            else numb[i] = max((long long)0, a[i]-b[n-1]);
            sm += numb[i];
            //cout << i << ' ' << numb[i] << endl;
        }

        ll out = sm - numb[0] + a[0];
        for (int i = 0; i < n; i++) {
            out = min(out, sm-numb[i] + a[i]);
        }
        cout << out << endl;
    }
}