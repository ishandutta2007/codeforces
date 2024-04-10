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
    	int n, k;
    	cin >> n >> k;
    	int now = 1;
    	int res = 0;
    	for(int i = 0; i < 30; i++) {
    		if((k >> i) & 1) {
    			res = (res + now) % mod;
    		}
    		now = ((ll)now * n) % mod;
    	}
    	cout << res << '\n';
    }
}