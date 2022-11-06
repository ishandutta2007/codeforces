#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int,int>freq;
		int mx = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			freq[x]++;
			mx = max(mx,freq[x]);
		}
		cout << max(n%2,2*mx-n) << "\n";
	}
	return 0;
}