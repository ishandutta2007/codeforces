#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vector<string> a;
vvi dp1, dp2, dp3, dp4;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    dp1.assign(n, vi(m, 1));
    dp2.assign(n, vi(m, 1));
    dp3.assign(n, vi(m, 1));
    dp4.assign(n, vi(m, 1));
    for(int i = 1; i < n; i++) {
    	for(int j = 1; j < m; j++) {
    		if(a[i - 1][j] != a[i][j] || a[i][j - 1] != a[i][j]) {
    			continue;
    		}
    		dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) + 1;
    	}
    }
    for(int i = n - 2; i >= 0; i--) {
    	for(int j = 1; j < m; j++) {
    		if(a[i + 1][j] != a[i][j] || a[i][j - 1] != a[i][j]) {
    			continue;
    		}
    		dp2[i][j] = min(dp2[i + 1][j], dp2[i][j - 1]) + 1;
    	}
    }
    for(int i = 1; i < n; i++) {
    	for(int j = m - 2; j >= 0; j--) {
    		if(a[i - 1][j] != a[i][j] || a[i][j + 1] != a[i][j]) {
    			continue;
    		}
    		dp3[i][j] = min(dp3[i - 1][j], dp3[i][j + 1]) + 1;
    	}
    }
    for(int i = n - 2; i >= 0; i--) {
    	for(int j = m - 2; j >= 0; j--) {
    		if(a[i + 1][j] != a[i][j] || a[i][j + 1] != a[i][j]) {
    			continue;
    		}
    		dp4[i][j] = min(dp4[i + 1][j], dp4[i][j + 1]) + 1;
    	}
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		res += min(min(dp1[i][j], dp2[i][j]), min(dp3[i][j], dp4[i][j]));
    	}
    }
    cout << res;
}