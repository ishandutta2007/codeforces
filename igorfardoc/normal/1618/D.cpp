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
    	int ans = 0;
    	sort(a.begin(), a.end());
    	reverse(a.begin(), a.end());
    	for(int i = 0; i < k; i++) {
    		ans += a[i + k] / a[i];
    	}
    	for(int i = 2 * k; i < n; i++) {
    		ans += a[i];
    	}
    	cout << ans << '\n';
    }
}