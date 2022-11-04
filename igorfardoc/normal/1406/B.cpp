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
    	sort(a.begin(), a.end());
    	ll now = 1;
    	ll ans = -1000000000000000000ll;
    	for(int i = 0; i <= 5; i++) {
    		now = 1;
    		for(int j = 0; j < i; j++) {
    			now *= a[j];
    		}
    		for(int j = 0; j < 5 - i; j++) {
    			now *= a[n - 1 - j];
    		}
    		ans = max(now, ans);
    	}
    	cout << ans << '\n';
    }
}