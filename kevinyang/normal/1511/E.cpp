#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)998244353;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int f(int x){
	x--;
	int ans = 3*x+1;
	ans*=modpow(2,x); ans%=mod;
	if(x%2==1)ans++;
	else ans+=mod-1;
	ans%=mod;
	ans*=modpow(9,mod-2);
	ans%=mod;
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<char>>arr(n+1,vector<char>(m+1));
	int cnt = 0;
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			arr[i][j] = s[j-1];
			if(arr[i][j]=='o')cnt++;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int num = 0;
		for(int j = 1; j<=m; j++){
			if(arr[i][j]=='o')num++;
			else{
				if(num==0)continue;
				ans+=modpow(2,cnt-num)*f(num)%mod;
				ans%=mod;
				num = 0;
			}
		}
		if(num){
			ans+=modpow(2,cnt-num)*f(num)%mod;
			ans%=mod;
			num = 0;
		}
		//cout << ans << "\n";
	}
	for(int j = 1; j<=m; j++){
		int num = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i][j]=='o')num++;
			else{
				if(num==0)continue;
				ans+=modpow(2,cnt-num)*f(num)%mod;
				ans%=mod;
				num = 0;
			}
		}
		if(num){
			ans+=modpow(2,cnt-num)*f(num)%mod;
			ans%=mod;
			num = 0;
		}
		//cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}