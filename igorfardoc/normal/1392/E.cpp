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
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = n - 1; i >= 0; i--) {
    	for(int j = n - 1; j >= 0; j--) {
    		if((n - i) % 2 == 0) {
    			a[i][j] = 0;
    			continue;
    		}
    		if((i == 0 && j == 0) || (i == n - 1 && j == n - 1)) {
    			a[i][j] = 0;
    			continue;
    		}
    		int num = i + j;
    		a[i][j] = (1ll << num);
    	}
    }
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cout << a[i][j] << ' ';
    	}
    	cout << '\n';
    }
    cout << endl;
    int q;
    cin >> q;
    for(int o = 0; o < q; o++) {
    	ll k;
    	cin >> k;
    	vector<pair<int, int>> ans;
    	int x = n - 1;
    	int y = n - 1;
    	ans.push_back({x, y});
    	while(x != 0 || y != 0) {
    		if(x == 0) {
    			ans.push_back({x, y - 1});
    			--y;
    			continue;
    		}
    		if(y == 0) {
    			ans.push_back({x - 1, y});
    			--x;
    			continue;
    		}
    		if(a[x][y - 1] != 0) {
    			if(k & a[x][y - 1]) {
    				--y;
    			} else {
    				--x;
    			}
    		} else {
    			if(k & a[x - 1][y]) {
    				--x;
    			} else {
    				--y;
    			}
    		}
    		ans.push_back({x, y});
    	}
    	reverse(ans.begin(), ans.end());
    	for(auto& p : ans) {
    		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    	}
    	cout << endl;
    }
}