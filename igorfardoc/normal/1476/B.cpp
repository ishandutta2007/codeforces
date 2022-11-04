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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll sum = a[0];
    	ll ans = 0;
    	for(int i = 1; i < n; i++) {
    		ans = max(ans, (((ll)a[i] * 100 - 1) / k + 1) - sum);
    		sum += a[i];
    	}
    	cout << ans << '\n';
    }
}