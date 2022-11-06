#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k,z;
		cin >> n >> k >> z;
		vector<int>psa(n+1);
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			psa[i] = psa[i-1] + arr[i];
		}
		int mx = 0;
		for(int i = 1; i<n; i++){
			int cur = 0;
			int moves = k;
			cur+=psa[min(i+1,k+1)];
			moves-=min(i,k);
			for(int j = 0; j<min(2*z,moves); j++){
				if(j%2==0)cur+=arr[i];
				else cur+=arr[i+1];
			}
			moves-=min(2*z,moves);
			cur+=psa[min(n,i+1+moves)]-psa[i+1];
			mx = max(mx,cur);
		}
		cout << mx << "\n";
	}
	return 0;
}