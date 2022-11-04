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
    	int x, y;
    	cin >> x >> y;
    	ll ans = 0;
    	for(int i = 1; i * i <= x; i++) {
    		int maxans = x / i - 1;
    		int minans = i + 1;
    		ans += max(0, min(maxans, y) - minans + 1);
    	}
    	cout << ans << '\n';
    }
}