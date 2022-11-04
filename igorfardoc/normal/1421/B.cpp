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
    	cin >> n;
    	vector<string> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vector<pair<int, int>> ans;
    	if(a[0][1] == a[1][0]) {
    		if(a[n - 1][n - 2] == a[0][1]) {
    			ans.push_back({n - 1, n - 2});
    		}
    		if(a[n - 2][n - 1] == a[0][1]) {
    			ans.push_back({n - 2, n - 1});
    		}
    	} else if(a[n - 1][n - 2] == a[n - 2][n - 1]) {
    		if(a[0][1] == a[n - 1][n - 2]) {
    			ans.push_back({0, 1});
    		}
    		if(a[1][0] == a[n - 1][n - 2]) {
    			ans.push_back({1, 0});
    		}
		} else if(a[0][1] == a[n - 1][n - 2]) {
			ans.push_back({0, 1});
			ans.push_back({n - 2, n - 1});
		} else {
			ans.push_back({0, 1});
			ans.push_back({n - 1, n - 2});
		}
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
		}
	}
}