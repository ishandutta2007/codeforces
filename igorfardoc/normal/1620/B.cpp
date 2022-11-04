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
    	int w, h;
    	cin >> w >> h;
    	vvi a(4);
    	for(int i = 0; i < 4; i++) {
    		int k;
    		cin >> k;
    		a[i].resize(k);
    		for(int j = 0; j < k; j++) {
    			cin >> a[i][j];
    		}
    	}
    	ll ans = 0;
    	ans = (ll)(h) * (a[0][a[0].size() - 1] - a[0][0]);
    	ans = max(ans, (ll)(h) * (a[1][a[1].size() - 1] - a[1][0]));
    	ans = max(ans, (ll)(w) * (a[2][a[2].size() - 1] - a[2][0]));
    	ans = max(ans, (ll)(w) * (a[3][a[3].size() - 1] - a[3][0]));
    	cout << ans << '\n';
    }
}