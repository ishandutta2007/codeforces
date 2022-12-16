#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        if (k == 1) {
            cout << "1 1" << endl;
            continue;
        } else if (k == 2) {
            cout << "1 2" << endl;
            continue;
        }
        ll rem = k;
        ll before = -1;
        for (ll i = 0; i < k; i++) {
            if (i*i >= rem) {
                before = i-1;
                break;
            }
        }

        rem -= before*before;
        //cout << "hello " << before << ' ' << rem << endl;

        if (rem <= before+1) {
            //cout << rem << endl;
            //cout << before+1 << ' ' << rem << endl;
            cout << rem << ' ' << before+1 << endl;
        } else {
            rem -= before;
            //cout << before+1-rem << ' ' << before+1 << endl;
            cout << before+1 << ' ' << before+1-rem+1 << endl;
        }
    }
}