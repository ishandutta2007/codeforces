#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,p,k;
	cin >> n >> p >> k;
	vector<int>arr(n+1);
	map<int,int>hm;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int v = arr[i]*arr[i]%p*arr[i]%p*arr[i]%p;
		v-=k*arr[i]%p;
		v+=p;
		v%=p;
		ans+=hm[v];
		hm[v]++;
	}
	cout << ans << "\n";
	return 0;
}