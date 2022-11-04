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
    	vvi a(n, vi(m));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
    		}
    	}
    	ll ans = 0;
    	for(int i = 0; i < (n - 1) / 2 + 1; i++) {
    		for(int j = 0; j < (m - 1) / 2 + 1; j++) {
    			vi ch;
    			ch.push_back(a[i][j]);
    			if(i != n - 1 - i) {
    				ch.push_back(a[n - i - 1][j]);
    			}
    			if(j != m - 1 - j) {
    				ch.push_back(a[i][m - j - 1]);
    			}
    			if(j != m - 1 - j && i != n - 1 - i) {
    				ch.push_back(a[n - i - 1][m - j - 1]);
    			}
    			sort(ch.begin(), ch.end());
    			int need = 1;
    			if(ch.size() == 1) {
    				continue;
    			}
    			for(int i = 0; i < ch.size(); i++) {
    				ans += abs(ch[i] - ch[need]);
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}