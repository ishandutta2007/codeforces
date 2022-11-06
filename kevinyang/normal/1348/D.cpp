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
		if(n==1){
			cout << "0\n";
			continue;
		}
		int idx = 0;
		for(int i = 1; i<=30; i++){
			if((1<<(i+1))-1>=n){
				idx = i;
				break;
			}
		}
		vector<int>ans(idx+1);
		for(int i = 0; i<idx; i++){
			ans[i] = (1<<i);
		}
		reverse(ans.begin(),ans.end());
		int rem = (1<<(idx+1))-1-n;
		//cout << rem << "\n";
		for(int i = idx; i>=1; i--){
			while(rem>=((1<<i)-1)){
				rem-=((1<<i)-1);
				for(int j = 1; j<=i; j++){
					int dis = i-j-1;
					dis = max(dis,0LL);
					ans[j]-=(1<<dis);
				}
			}
		}
		cout << idx << "\n";
		for(int i = idx; i>=1; i--){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}