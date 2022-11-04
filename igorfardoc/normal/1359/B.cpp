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
    	int n, m, x, y;
    	cin >> n >> m >> x >> y;
    	vector<string> s(n);
    	for(int i = 0; i < n; i++) {
    		cin >> s[i];
    	}
    	if(x * 2 < y) {
    		y = x * 2;
    	}
    	int ans = 0;
    	for(int i = 0; i < n; i++) {
    		int prev = -1;
    		for(int j = 0; j < m; j++) {
    			if(s[i][j] == '.') {
    				if(prev == -1) {
    					prev = j;
    				} else {
    					ans += y;
    					prev = -1;
    				}
    			} else {
    				if(prev != -1) {
    					prev = -1;
    					ans += x;
    				}
    			}
    		}
    		if(prev != -1) {
    			ans += x;
    		}
    	}
    	cout << ans << '\n';
    }
}