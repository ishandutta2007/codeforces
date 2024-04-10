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
    	vector<map<int, int>> a(n);
    	vi am(n, 0);
    	vi sz(n, 0);
    	for(int i = 0; i < n; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		++am[u];
    		a[v][u]++;
    		++sz[v];
    	}
    	ll res = ((ll)n * (n - 1) * (n - 2)) / 6;
    	for(int i = 0; i < n; i++) {
    		for(const auto& el : a[i]) {
    			int amount = el.second;
    			int val = el.first;
    			res -= ((ll)amount * (amount - 1) * (n - 2));
    			res -= ((ll)amount * (sz[i] - amount) * (am[val] - amount));
    		}
    	}
    	cout << res << '\n';
    }
}