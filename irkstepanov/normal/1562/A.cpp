#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	ll l, r;
    	cin >> l >> r;
    	if (r < l * 2 - 1) {
    		cout << r - l << "\n";
    	} else {
    		ll x = (r + 1) / 2;
    		cout << x - 1 << "\n";
    	}
    }

}