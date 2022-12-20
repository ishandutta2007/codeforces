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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int aind = 0;
        int bind = n-1;
        ll lasta = 0;
        ll lastb = 0;
        ll sma = 0;
        ll smb = 0;
        ll moves = 0;
        while (true) {
            // a goes
            moves++;
            ll curra = 0;
            while (curra <= lastb) {
                if (aind > bind) break;
                sma += a[aind];
                curra += a[aind];
                aind++;
            }
            lasta = curra;
            if (aind > bind) break;

            ll currb = 0;
            moves++;
            while (currb <= lasta) {
                if (aind > bind) break;
                smb += a[bind];
                currb += a[bind];
                bind--;
            }
            lastb = currb;
            if (aind > bind) break;
        }
        cout << moves << ' ' << sma << ' ' << smb << endl;
    }
}