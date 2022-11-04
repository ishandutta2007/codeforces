#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	ll k;
    	ll x;
    	cin >> k >> x;
    	ll l = 0;
    	ll r = 2 * k;
    	while(r - l > 1) {
    		ll mid = ((ll)l + r) / 2;
    		ll bef = min(mid, k);
    		ll res = (ll)bef * (bef + 1) / 2;
    		if(mid > k) {
    			res += (ll)k * (k - 1) / 2 - (ll)(2 * k - mid) * (2 * k - mid - 1) / 2;
    		}
    		if(res >= x) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << min(l + 1, 2 * k - 1) << '\n';
    }
}