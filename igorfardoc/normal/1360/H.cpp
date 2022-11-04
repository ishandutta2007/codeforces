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
    	swap(n, m);
    	vector<ll> a(m);
    	for(int i = 0; i < m; i++) {
    		string s;
    		cin >> s;
    		ll x = 0;
    		for(int j = 0; j < n; j++) {
    			if(s[n - 1 - j] == '1') {
    				x ^= (1ll << j);
    			}
    		}
    		a[i] = x;
    	}
    	sort(a.begin(), a.end());
    	ll k = (1ll << n) - m;
    	ll need = (k - 1) / 2;
    	int now = 0;
    	while(now < a.size() && a[now] <= need) {
    		++now;
    		++need;
    	}
    	vi ans(n);
    	for(int i = 0; i < n; i++) {
    		if((need >> i) & 1) {
    			ans[n - i - 1] = 1;
    		} else {
    			ans[n - i - 1] = 0;
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		cout << ans[i];
    	}
    	cout << '\n';
    }
}