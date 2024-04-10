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

ll cnt[4][4];

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    while (n--) {
    	int x, y;
    	cin >> x >> y;
    	++cnt[x % 4][y % 4];
    }

    ll ans = 0;
    for (int a = 0; a < 4; a += 2) {
    	for (int b = 0; b < 4; b += 2) {
    		ll x = cnt[a][b];
    		ans += x * (x - 1) * (x - 2) / 6;
    		for (int c = 0; c < 4; c += 2) {
    			for (int d = 0; d < 4; d += 2) {
    				if (a == c && b == d) {
    					continue;
    				}
    				ans += x * (x - 1) * cnt[c][d] / 2;
    			}
    		}
    	}
    }

    cout << ans << "\n";

}