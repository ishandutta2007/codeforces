#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll p[19];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    p[0] = 1;
    for(int i = 1; i <= 18; i++) {
    	p[i] = p[i - 1] * 10;
    }
    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	++k;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll ans = 0;
    	for(int i = 0; i < n - 1; i++) {
    		if(p[a[i + 1] - a[i]] - 1 >= k) {
    			ans += k * p[a[i]];
    			k = 0;
    			break;
    		} else {
    			k -= p[a[i + 1] - a[i]] - 1;
    			ans += (p[a[i + 1] - a[i]] - 1) * p[a[i]];
    		}
    	}
    	ans += k * p[a[n - 1]];
    	cout << ans << '\n';
    }
}