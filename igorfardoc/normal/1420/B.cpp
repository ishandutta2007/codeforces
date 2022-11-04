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
    	vi am(31);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		for(int j = 30; j >= 0; j--) {
    			if((a >> j) & 1) {
    				++am[j];
    				break;
    			}
    		}
    	}
    	ll ans = 0;
    	for(int i = 0; i < 31; i++) {
    		ans += (ll)(am[i]) * (am[i] - 1) / 2;
    	}
    	cout << ans << '\n';
    }
}