#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int mod = (int)1e9+7;
	int ans = 1;
	for(int i = 1; i<=n; i++){
		ans*=i; ans%=mod;
	}
	int pow = 1;
	for(int i = 0; i<n-1; i++){
		pow*=2;
		pow%=mod;
	}
	ans-=pow;
	ans+=mod;
	ans%=mod;
	cout << ans << "\n";
	return 0;
}