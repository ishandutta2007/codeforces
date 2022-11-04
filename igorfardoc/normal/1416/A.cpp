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
    	vi a(n);
    	vi ans(n + 1, 10000000);
    	vvi pos(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		--a[i];
    		pos[a[i]].push_back(i);
    	}
    	for(int i = 0; i < n; i++) {
    		if(pos[i].empty()) {
    			continue;
    		}
    		int maxhere = pos[i][0];
    		maxhere = max(maxhere, n - 1 - pos[i][pos[i].size() - 1]);
    		for(int j = 0; j < (int)pos[i].size() - 1; j++) {
    			maxhere = max(maxhere, pos[i][j + 1] - pos[i][j] - 1);
    		}
    		ans[maxhere + 1] = min(ans[maxhere + 1], i);
    	}
    	int now = 10000000;
    	for(int i = 1; i <= n; i++) {
    		now = min(now, ans[i]);
    		if(now == 10000000) {
    			cout << "-1 ";
    		} else {
    			cout << now + 1 << ' ';
    		}
    	}
    	cout << '\n';
    }
}