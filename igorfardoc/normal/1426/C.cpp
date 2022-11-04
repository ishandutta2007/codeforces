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
    	int ans = 10000000;
    	for(int i = 0; i < min(n, 50000); i++) {
    		ans = min(ans, i + (n - 1 - i - 1) / (i + 1) + 1);
    	}
    	cout << ans << '\n';

    }
}