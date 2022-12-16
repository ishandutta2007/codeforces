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

#define MAXN 200'010

ll n, m;
ll a[MAXN];
ll workload[MAXN];

bool works(ll amt) {
    rep(i, 0, n) workload[i] = 0;

    ll jobsleft = 0;
    rep(i, 0, m) {
        if (workload[a[i]] < amt) {
            workload[a[i]]++;
        } else {
            jobsleft++;
        }
    }
    ll capleft = 0;
    rep(i, 0, n) {
        capleft += (amt-workload[i])/2;
    }
    return capleft >= jobsleft;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        rep(i, 0, m) {
            cin >> a[i];
            a[i]--;
        }

        ll lo = 0;
        ll hi = m*2 + 1;
        while (hi-lo > 3) {
            ll mid = (lo+hi)/2;
            
            if (works(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        rep(i, lo-5, hi+5) {
            if (i <= 0) continue;
            if (works(i)) {
                cout << i << '\n';
                break;
            }
        }
        //cout << hi << '\n';
    }
}