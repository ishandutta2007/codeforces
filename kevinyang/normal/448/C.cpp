#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr(5001);
int n;
int f(int i, int j, int remove){
	if(i==j)return 0LL;
	if(j-i==1){
		return min(arr[i]-remove,1LL);
	}
	int mn = (int)1e18;
	for(int k = i; k<j; k++){
		mn = min(mn,arr[k]);
	}
	if(mn-remove>=j-i)return j-i;
	int cur = i;
	int ret = mn-remove;
	for(int k = i; k<j; k++){
		if(arr[k]==mn){
			ret+=f(cur,k,mn);
			cur = k+1;
		}
	}
	ret+=f(cur,j,mn);
	return min(ret,j-i);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int cur = 0;
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(arr[i]==0){
			ans+=f(cur,i,0LL);
			cur = i+1;
		}
	}
	ans+=f(cur,n,0LL);
	cout << ans << "\n";
	return 0;
}