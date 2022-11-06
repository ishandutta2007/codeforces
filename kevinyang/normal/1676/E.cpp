#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		sort(arr.begin()+1,arr.end());
		reverse(arr.begin()+1,arr.end());
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		while(q--){
			int x;
			cin >> x;
			int v = lower_bound(psa.begin(),psa.end(),x)-psa.begin();
			if(v>n)cout << "-1\n";
			else cout << v << "\n";
		}
	}
	return 0;
}