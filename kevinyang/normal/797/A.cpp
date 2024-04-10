#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>ans;
	int cnt = 0;
	int nn = n;
	if(k==1){
		cout << n << "\n";
		return 0;
	}
	for(int i = 2; i<n; i++){
		while(nn%i==0){
			cnt++;
			nn/=i;
			ans.push_back(i);
		}
	}
	if(cnt<k){
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i<k-1; i++){
		n/=ans[i];
		cout << ans[i] << " ";
	}
	cout << n << "\n";
	return 0;
}