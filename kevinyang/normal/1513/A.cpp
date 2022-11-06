#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if((n-1)/2<k){
			cout << "-1\n";
			continue;
		}
		if(k==0){
			for(int i = 1; i<=n; i++){
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		vector<int>ans(n+1);
		int cur = n-k+1;
		for(int i = 2; i<=n; i+=2){
			ans[i] = cur;
			if(cur==n)break;
			cur++;
		}
		cur = 1;
		for(int i = 1; i<=n; i++){
			if(ans[i]==0){
				ans[i] = cur;
				cur++;
			}
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}