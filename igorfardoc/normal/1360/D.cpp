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
    	int n, k;
    	cin >> n >> k;
    	int ans = 1000000000;
    	for(int i = 1; i * i <= n; i++) { 
    		if(n % i != 0) {
    			continue;
    		}
    		if(i <= k) {
    			ans = min(ans, n / i);
    		}
    		if(n / i <= k) {
    			ans = min(ans, i);
    		}
    	}
    	cout << ans << '\n';
    }
}