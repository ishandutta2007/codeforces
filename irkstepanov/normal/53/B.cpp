#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

ll opta = 0, optb = 0;

void upd(ll a, ll b) {
	if (a * b > opta * optb) {
		opta = a, optb = b;
	} else if (a * b == opta * optb && a > opta) {
		opta = a, optb = b;
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y;
    cin >> x >> y;

    for (ll a = 1; a <= x; a *= 2) {
    	ll lf = max(ll(1), (a * 4 + 4) / 5);
    	ll rg = min(y, (a * 5) / 4);
    	if (lf <= rg) {
    		upd(a, rg);
    	}
    }

    for (ll b = 1; b <= y; b *= 2) {
    	ll lf = max(ll(1), (b * 4 + 4) / 5);
    	ll rg = min(x, (b * 5) / 4);
    	if (lf <= rg) {
    		upd(rg, b);
    	}
    }

    cout << opta << " " << optb << "\n";

}