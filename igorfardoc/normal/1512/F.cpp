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
    	int n, c;
    	cin >> n >> c;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vi b(n);
    	for(int i = 0; i < n - 1; i++) {
    		cin >> b[i];
    	}
    	ll t = 0;
    	ll now = 0;
    	ll ans = 1000000000000000000ll;
    	for(int i = 0; i < n; i++) {
    		ans = min(ans, t + (c - now - 1) / a[i] + 1);
    		if(i == n - 1) {
    			break;
    		}
    		if(b[i] >= c) {
    			break;
    		}
    		if(b[i] <= now) {
    			now -= b[i];
    			++t;
    			continue;
    		}
    		ll need = (b[i] - now - 1) / a[i] + 1;
    		t += need + 1;
    		now += need * a[i];
    		now -= b[i];
    	}
    	cout << ans << '\n';
    }
}