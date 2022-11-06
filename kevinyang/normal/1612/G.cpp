#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
int sumlr(int l, int r){
	return (l+r)*(r-l+1)/2%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>psa((int)2e6+10);
	vector<int>fact((int)2e6+1);
	fact[0] = 1;
	
	for(int i = 1; i<=(int)2e6; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	int extra = (int)1e6+5;
	for(int i = 1; i<=n; i++){
		psa[extra-(arr[i]-1)]++;
		psa[extra+(arr[i]-1)+2]--;
	}
	for(int i = 2; i<=(int)2e6+9; i++){
		psa[i]+=psa[i-2];
	}
	int ans = 0;
	int cnt = 1;
	int cur = 0;
	for(int i = 2; i<=(int)2e6+9; i++){
		ans+=sumlr(cur,cur+psa[i]-1)*(i-extra)%mod;
		ans%=mod;
		cur+=psa[i];
		cnt*=fact[psa[i]];
		assert(psa[i]>=0);
		cnt%=mod;
	}
	cout << ans << " " << cnt << "\n";
	return 0;
}