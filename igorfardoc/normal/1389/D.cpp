#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



signed main()
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
    	int n, k;
    	cin >> n >> k;
    	int l1, r1, l2, r2;
    	cin >> l1 >> r1 >> l2 >> r2;
    	int inter = min(r1, r2) - max(l1, l2);
    	if(inter >= 0) {
    		ll now = (ll)inter * n;
    		if(now >= k) {
    			cout << 0 << '\n';
    			continue;
    		}
    		ll can = (ll)(max(r1, r2) - min(l1, l2)) * n;
    		if(can >= k) {
    			cout << k - now << '\n';
    			continue;
    		}
    		cout << can - now + (ll)(k - can) * 2 << '\n';
    		continue;
    	}
    	ll ans = 10000000000000000ll;
    	for(int i = 1; i <= n; i++) {
    		ll here = (max(l1, l2) - min(r1, r2)) * i;
    		ll can = (ll)(max(r1, r2) - min(l1, l2)) * i;
    		if(can >= k) {
    			here += k;
    		} else {
    			here += can;
    			here += (ll)(k - can) * 2;
    		}
    		ans = min(ans, here);
    	}
    	cout << ans << '\n';
    }
}