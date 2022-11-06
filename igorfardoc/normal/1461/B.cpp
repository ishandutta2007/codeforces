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
    	vector<string> a(n);
    	for(int i = 0; i < n;i++) {
    		cin >> a[i];
    	}
    	vvi pref(n, vi(m + 1, 0));
    	for(int i = 0; i < n; i++) {
    		for(int j = 1; j <= m; j++) {
    			pref[i][j] = pref[i][j - 1] + (a[i][j - 1] == '*');
    		}
    	}
    	int ans = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			for(int k = 1; i + k <= n; k++) {
    				if(j - k + 1 < 0 || j + k - 1 >= m) {
    					break;
    				}
    				if(pref[i + k - 1][j + k] - pref[i + k - 1][j - k + 1] != 2 * k - 1) {
    					break;
    				}
    				++ans;
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}