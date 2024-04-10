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
    	int n;
    	ll h;
    	cin >> n >> h;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll l = 0;
    	ll r = 1000000000000000000ll;
    	while(r - l > 1) {
    		ll mid = (l + r) / 2;
    		ll can = 0;
    		for(int i = 0; i < n - 1; i++) {
    			can += min(mid, (ll)a[i + 1] - a[i]);
    		}
    		can += mid;
    		if(can >= h) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << r << '\n';
    }
}