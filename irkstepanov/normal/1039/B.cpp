#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

mt19937 rr(time(0));

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll k;
    cin >> n >> k;

    ll l = 1, r = n;

    while (true) {
        while (r - l > 45) {
            ll m = (l + r) >> 1;
            cout << l << " " << m << endl;
            string s;
            cin >> s;
            if (s == "Yes") {
                l = max(l - k, ll(1));
                r = min(m + k, n);
            } else {
                l = max(m - k, ll(1));
                r = min(r + k, n);
            }
        }
        int x = rr() % (r - l + 1);
        ll pos = l + x;
        cout << pos << " " << pos << endl;
        string s;
        cin >> s;
        if (s == "Yes") {
            return 0;
        }
        l = max(l - k, ll(1));
        r = min(r + k, n);
    }

}