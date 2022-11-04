#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;


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
    	int ans = 0;
    	vi am1(n + 1, 0), am2(n + 1, 0);
    	for(int i = 0; i < n; i++) {
    		am1[a[i]] = (am1[a[i]] + am1[a[i]]) % mod;
    		if(a[i] + 2 <= n) {
				am2[a[i] + 2] = (am2[a[i] + 2] + am2[a[i] + 2]) % mod;
			}
    		if(a[i] == 0) {
    			am1[a[i]] = (am1[a[i]] + 1) % mod;
    		} else {
    			am1[a[i]] = (am1[a[i]] + am1[a[i] - 1]) % mod;
    			if(a[i] == 1) {
    				am2[a[i]] = (am2[a[i]] + am2[a[i]] + 1) % mod;
    			} else {
    				am2[a[i]] = ((ll)am2[a[i]] + am2[a[i]] + am1[a[i] - 2]) % mod;
    			}
    		}
    	}
    	for(int i = 0; i <= n; i++) {
    		ans = (ans + am1[i]) % mod;
    		ans = (ans + am2[i]) % mod;
    	}
    	cout << ans << '\n';
    }
}