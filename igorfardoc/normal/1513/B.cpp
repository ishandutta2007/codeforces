#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;



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
    	set<int> s;
    	for(int i = 0; i < 30; i++) {
    		bool all0 = true;
    		bool all1 = true;
    		for(int j = 0; j < n; j++) {
    			if((a[j] >> i) & 1) {
    				all0 = false;
    			} else {
    				all1 = false;
    			}
    		}
    		if(all1 || all0) {
    			continue;
    		}
    		for(int j = 0; j < n; j++) {
    			if((a[j] >> i) & 1) {
    				s.insert(j);
    			}
    		}
    	}
    	int res = 0;
    	int sz = s.size();
    	int ok = n - sz;
    	res = ((ll)ok * (ok - 1)) % mod;
    	for(int i = 1; i <= n - 2; i++) {
    		res = ((ll)res * i) % mod;
    	}
    	cout << res << '\n';
    }
}