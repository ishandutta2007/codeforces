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
    	int ans = 0;
    	vi am(102);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		am[a]++;
    	}
    	bool two = true;
    	for(int i = 0; i <= 101; i++) {
    		if(two && am[i] >= 2) {
    			ans += 2;
    		} else if(am[i] >= 1) {
    			++ans;
    			two = false;
    		} else {
    			break;
    		}
    	}
    	cout << ans << '\n';
    }
}