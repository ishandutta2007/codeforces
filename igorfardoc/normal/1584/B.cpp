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
    	if(m % 3 == 0) {
    		swap(n, m);
    	}
    	if(n % 3 == 0) {
    		cout << (ll)m * n / 3 << '\n';
    		continue;
    	}
    	ll ans = 100000000000000000ll;
    	if(n % 3 == 1 && m != 1) {
    		ans = min(ans, (ll)m * (n / 3) + (m - 1) / 3 + 1);
    	}
    	if(n % 3 == 2 && m != 1) {
    		ans = min(ans, (ll)m * (n / 3) + 2 * ((m - 1) / 3 + 1));
    	}
    	if(m % 3 == 1 && n != 1) {
    		ans = min(ans, (ll)n * (m / 3) + (n - 1) / 3 + 1);
    	}
    	if(m % 3 == 2 && n != 1) {
    		ans = min(ans, (ll)n * (m / 3) + 2 * ((n - 1) / 3 + 1));
    	}
    	cout << ans << '\n';
    }
}