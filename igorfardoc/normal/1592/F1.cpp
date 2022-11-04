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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    vector<vector<bool>> b(n, vector<bool>(m, false));
    vector<vector<bool>> here(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		char c;
    		cin >> c;
    		if(c == 'W') {
    			a[i][j] = false;
    		} else {
    			a[i][j] = true;
    		}
    	}
    }
    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
    	bool now = false;
    	for(int j = m - 1; j >= 0; j--) {
    		now = now ^ b[i][j];
    		if(a[i][j] ^ now == false) {
    			continue;
    		}
    		//cout << i << ' ' << j << endl;
    		++res;
    		here[i][j] = true;
    		now = !now;
    		for(int k = i - 1; k >= 0; k--) {
    			b[k][j] = !b[k][j];
    		}
    	}
    }
    if(here[n - 1][m - 1]) {
    	for(int i = 0; i < n - 1; i++) {
    		for(int j = 0; j < m - 1; j++) {
    			if(here[i][m - 1] && here[n - 1][j] && here[i][j]) {
    				--res;
    				cout << res;
    				return 0;
    			}
    		}
    	}
    }
    cout << res;
}