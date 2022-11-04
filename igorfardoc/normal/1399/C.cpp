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
    	vi am(n + 1, 0);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		am[a]++;
    	}
    	int ans = 0;
    	for(int i = 2; i <= 2 * n; i++) {
    		auto a = am;
    		int ans1 = 0;
    		for(int j = 1; j <= n; j++) {
    			while(a[j] > 0) {
    				--a[j];
    				if(i - j >= 1 && i - j <= n && a[i - j] > 0) {
    					--a[i - j];
    					++ans1;
    				}
    			}
    		}
    		ans = max(ans, ans1);
    	}
    	cout << ans << '\n';
    }
}