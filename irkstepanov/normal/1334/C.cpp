#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<ll> a(n), b(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i] >> b[i];
    	}
    	vector<ll> d(n);
    	for (int i = 0; i < n; ++i) {
    		d[i] = min(b[i], a[(i + 1) % n]);
    	}
    	sort(all(d));
    	ll ans = 0;
    	for (int i = 0; i < n; ++i) {
    		ans += a[i];
    		if (i) {
    			ans -= d[i];
    		}
    	}
    	cout << ans << "\n";
    }

}