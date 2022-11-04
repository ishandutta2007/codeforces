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
    	cin >> m >> n;
    	vvi a(m, vi(n));
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			cin >> a[i][j];
    		}
    	}
    	int l = 0;
    	int r = 1000000001;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		bool ok = true;
    		for(int j = 0; j < n; j++) {
    			int mx = -1;
    			for(int i = 0; i < m; i++) {
    				mx = max(mx, a[i][j]);
    			}
    			if(mx < mid) {
    				ok = false;
    				break;
    			}
    		}
    		if(!ok) {
    			r = mid;
    			continue;
    		}
    		ok = false;
    		for(int i = 0; i < m; i++) {
    			int here = 0;
    			for(int j = 0; j < n; j++) {
    				if(a[i][j] >= mid) {
    					++here;
    				}
    			}
    			if(here >= 2) {
    				ok = true;
    				break;
    			}
    		}
    		if(ok) {
    			l = mid;
    		} else {
    			r = mid;
    		}
    	}
    	cout << l << '\n';
    }
}