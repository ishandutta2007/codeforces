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
    	ll x;
    	cin >> n >> x;
    	vector<ll> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	sort(all(a));
    	reverse(all(a));
    	int ans = 0;
    	ll sum = 0;
    	for (int i = 0; i < n; ++i) {
    		sum += a[i];
    		if (sum >= x * (i + 1)) {
    			ans = i + 1;
    		}
    	}
    	cout << ans << "\n";
    }

}