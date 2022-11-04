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
    	vi a(n), b(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		--a[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> b[i];
    		--b[i];
    	}
    	vi cost(2 * n, n + 1);
    	for(int i = 0; i < n; i++) {
    		cost[a[i]] = i;
    	}
    	vi pref(2 * n);
    	pref[0] = cost[0];
    	for(int i = 1; i < 2 * n; i++) {
    		pref[i] = min(pref[i - 1], cost[i]);
    	}
    	int ans = n + 1;
    	for(int i = 0; i < n; i++) {
    		ans = min(ans, i + pref[b[i]]);
    	}
    	cout << ans << '\n';
    }
}