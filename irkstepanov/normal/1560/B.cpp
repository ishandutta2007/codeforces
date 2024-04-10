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

//const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;


    while (tt--) {
    	ll a, b, c;
    	cin >> a >> b >> c;
    	if (a > b) {
    		swap(a, b);
    	}
    	ll k = b - a;
    	if (c > k * 2 || a > k * 2 || b > k * 2) {
    		cout << "-1\n";
    	} else {
    		ll ans = c + k;
    		if (ans > k * 2) {
    			ans = c - k;
    		}
    		cout << ans << "\n";
    	}
    }

}