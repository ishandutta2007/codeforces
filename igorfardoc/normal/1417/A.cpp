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
    	int min1 = 100000;
    	int id1 = 0;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		if(a[i] < min1) {
    			min1 = a[i];
    			id1 = i;
    		}
    	}
    	int ans = 0;
    	for(int i = 0; i < n; i++) {
    		if(i == id1) {
    			continue;
    		}
    		ans += (k - a[i]) / min1;
    	}
    	cout << ans << '\n';
    }
}