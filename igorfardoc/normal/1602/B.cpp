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
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vvi b(2 * n, vi(n));
    	b[0] = a;
    	for(int i = 1; i < 2 * n; i++) {
    		vi am(n + 1, 0);
    		for(int j = 0; j < n; j++) {
    			am[b[i - 1][j]]++;
    		}
    		for(int j = 0; j < n; j++) {
    			b[i][j] = am[b[i - 1][j]];
    		}
    	}
    	int q;
    	cin >> q;
    	while(q--) {
    		int x, k;
    		cin >> x >> k;
    		cout << b[min(k, 2 * n - 1)][x - 1] << '\n';
    	}
    }
}