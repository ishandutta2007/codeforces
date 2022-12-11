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

    int n;
    int tt;
    cin >> tt;
    while (tt--) {
    	cin >> n;
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	ll ans = 0;
    	for (int i = 0; i + 1 < n; ++i) {
    		ans = max(ans, a[i] * a[i + 1]);
    	}
    	cout << ans << "\n";
    }

}