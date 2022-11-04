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
    	int n, m;
    	cin >> n >> m;
    	vvi mass(m, vi(n));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> mass[j][i];
    		}
    	}
    	vvi a;
    	set<int> used;
    	for(int i = 0; i < min(n, m); i++) {
    		int mx = -1;
    		int mxid = -1;
    		for(int j = 0; j < m; j++) {
    			if(used.find(j) != used.end()) continue;
    			int here = 0;
    			for(const auto& el : mass[j]) {
    				here = max(here, el);
    			}
    			if(here > mx) {
    				mxid = j;
    				mx = here;
    			}
    		}
    		used.insert(mxid);
    		a.push_back(mass[mxid]);
    	}
    	m = a.size();
    	vvi dp(m + 1, vi(1 << n, 0));
    	for(int i = 1; i <= m; i++) {
    		vi heremx(1 << n);
    		for(int mask = 0; mask < (1 << n); mask++) {
    			heremx[mask] = 0;
    			for(int j = 0; j < n; j++) {
    				int here = 0;
    				for(int k = 0; k < n; ++k) {
    					if((mask >> k) & 1) {
    						here += a[i - 1][(k + j) % n];
    					}
    				}
    				heremx[mask] = max(heremx[mask], here);
    			}
    		}
    		for(int mask = 0; mask < (1 << n); mask++) {
    			for(int mask1 = mask; ; mask1 = (mask1 - 1) & mask) {
    				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask1] + heremx[mask ^ mask1]);
    				if(mask1 == 0) break;
    			}
    		}
    	}
    	cout << dp[m][(1 << n) - 1] << '\n';
    }
}