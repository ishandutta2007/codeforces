#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
int pow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * pow((x * x) % mod, y / 2)) % mod;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i<=n/k; i++){
		int num = n/i-1;
		int den = k-1;
		int num2 = 1;
		int den2 = 1;
		for(int j = num; j>den; j--){
			num2*=j;
			num2%=mod;
		}
		for(int j = num-den; j>0; j--){
			den2*=j;
			den2%=mod;
		}
		int val = pow(den2,mod-2);
		num2*=val;
		num2%=mod;
		ans+=num2;
	}
	cout << ans%mod << "\n";
	return 0;
}