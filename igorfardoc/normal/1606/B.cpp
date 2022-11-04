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
    	ll n, k;
    	cin >> n >> k;
    	if(n == 1) {
    		cout << 0 << '\n';
    		continue;
    	}
    	ll now = 1;
    	for(int i = 0;; i++) {
    		if(now >= n) {
    			cout << i << '\n';
    			break;
    		}
    		if(now <= k) {
    			now *= 2;
    		} else {
    			cout << (n - now - 1) / k + 1 + i << '\n';
    			break;
    		}
    	}
    }

}