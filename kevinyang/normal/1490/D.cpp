#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr(101);
vector<int>ans(101);
void f(int l, int r, int d){
	if(r<l)return;
	if(r==l){
		ans[l] = d;
		return;
	}
	pair<int,int>mx = {0,0};
	for(int i = l; i<=r; i++){
		mx = max(mx,{arr[i],i});
	}
	ans[mx.second] = d;
	f(l,mx.second-1,d+1);
	f(mx.second+1,r,d+1);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		f(1,n,0);
		for(int i = 1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}