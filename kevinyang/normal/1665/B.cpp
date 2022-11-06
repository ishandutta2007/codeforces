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
		map<int,int>hm;
		int mx = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			hm[x]++;
			mx = max(mx,hm[x]);
		}
		int ans = 0;
		while(mx<n){
			ans++;
			ans+=mx;
			mx*=2;
		}
		ans-=mx-n;
		cout << ans << "\n";
	}
	return 0;
}