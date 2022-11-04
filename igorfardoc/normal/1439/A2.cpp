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
    	vector<vector<bool>> a(n, vector<bool>(m, false));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			char c;
    			cin >> c;
    			if(c == '1') {
    				a[i][j] = true;
    			}
    		}
    	}
    	vvi ans;
    	if(n % 2 == 1) {
    		if(a[n - 1][m - 1]) {
    			a[n - 1][m - 1] = false;
    			a[n - 1][m - 2] = !a[n - 1][m - 2];
    			a[n - 2][m - 1] = !a[n - 2][m - 1];
    			ans.push_back({n - 1, m - 1, n - 1, m - 2, n - 2, m - 1});
    		}
    		for(int j = 0; j < m; j++) {
    			if(a[n - 1][j]) {
    				ans.push_back({n - 1, j, n - 2, j, n - 2, j + 1});
    				a[n - 2][j] = !a[n - 2][j];
    				a[n - 2][j + 1] = !a[n - 2][j + 1];
    			}
    		}
    	}
    	if(m % 2 == 1) {
    		if(a[n / 2 * 2 - 1][m - 1]) {
    			a[n / 2 * 2 - 1][m - 1] = false;
    			a[n / 2 * 2 - 1][m - 2] = !a[n / 2 * 2 - 1][m - 2];
    			a[n / 2 * 2 - 2][m - 2] = !a[n / 2 * 2 - 2][m - 2];
    			ans.push_back({n / 2 * 2 - 1, m - 1, n / 2 * 2 - 1, m - 2, n / 2 * 2 - 2, m - 2});
    		}
			
			for(int i = 0; i < n / 2 * 2 - 1; i++) {
				if(a[i][m - 1]) {
					ans.push_back({i, m - 1, i, m - 2, i + 1, m - 2});
					a[i][m - 2] = !a[i][m - 2];
					a[i + 1][m - 2] = !a[i + 1][m - 2];
				}
			}
    	}
    	for(int i = 0; i + 1 < n; i+=2) {
    		for(int j = 0; j + 1 < m; j+=2) {
    			for(int o = 0; o < 4; o++) {
    				vector<pair<int, int>> b, c;
    				for(int k = 0; k < 2; k++) {
    					for(int l = 0; l < 2; l++) {
    						int x = i + k;
    						int y = j + l;
    						if(a[x][y]) {
    							b.push_back({x, y});
    						} else {
    							c.push_back({x, y});
    						}
						}
					}
					if(b.empty()) {
						break;
					}
					if(b.size() > 2) {
						vi here;
						for(int k = 0; k < 3; k++) {
							here.push_back(b[k].first);
							here.push_back(b[k].second);
							a[b[k].first][b[k].second] = false;
						}
						ans.push_back(here);
					} else {
						vi here;
						here.push_back(b[0].first);
						here.push_back(b[0].second);
						a[b[0].first][b[0].second] = false;
						for(int k = 0; k < 2; k++) {
							here.push_back(c[k].first);
							here.push_back(c[k].second);
							a[c[k].first][c[k].second] = true;
						}
						ans.push_back(here);
					}
				}
			}
		}
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++) {
			for(int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] + 1 << ' ';
			}
			cout << '\n';
		}
		cout << endl;
	}
}