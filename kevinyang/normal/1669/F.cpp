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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		int ans = 0;
		set<int>s;
		map<int,int>hm;
		for(int i = n; i>=1; i--){
			s.insert(psa[n]-psa[i]);
			hm[psa[n]-psa[i]] = n-i;
		}
		for(int i = 1; i<=n; i++){
			int v = psa[i];
			if(s.find(v)!=s.end()&&2*v<=psa[n]){
				ans = max(ans,i+hm[v]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}