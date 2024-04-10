#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = (int)998244353;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
int permute(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[x-y])%mod;
}
void precalc(){
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=2000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[2000000] = modpow(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n,k;
	cin >> n >> k;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>dp(n+1);//number of arrays such that a[i]!=a[i-1] and a[1]==a[n];
	vector<int>dp2(n+1);//number of arrays such that a[i]!=a[i-1] and a[1]!=a[n] both of these dp have fixed a[1]
	dp[1] = 1;
	for(int i = 2; i<=n; i++){
		dp2[i] += dp[i-1]*(k-1); dp2[i]%=mod;
		dp2[i] += dp2[i-1]*(k-2); dp2[i]%=mod;
		dp[i]+=dp2[i-1]; dp[i]%=mod;
	}
	int ans = 1;
	int prev = 0;
	int cnt = 0;
	for(int i = 1; i<=n; i+=2){
		if(arr[i]==-1)cnt++;
		else{
			if(prev==0){
				while(cnt>0){
					ans*=(k-1); ans%=mod;
					cnt--;
				}
				prev = arr[i];
			}
			else{
				if(prev==arr[i]){
					ans*=dp[cnt+2]; ans%=mod;
				}
				else{
					ans*=dp2[cnt+2]; ans%=mod;
					ans*=modpow(k-1,mod-2); ans%=mod;
				}
				prev = arr[i];
			}
			cnt = 0;
		}
	}
	if(prev>0){
		while(cnt>0){
			ans*=(k-1); ans%=mod;
			cnt--;
		}
	}
	else{
		cnt--;
		ans*=k;
		while(cnt>0){
			ans*=(k-1); ans%=mod;
			cnt--;
		}
	}
	prev = 0;
	for(int i = 2; i<=n; i+=2){
		if(arr[i]==-1)cnt++;
		else{
			if(prev==0){
				while(cnt>0){
					ans*=(k-1); ans%=mod;
					cnt--;
				}
				prev = arr[i];
			}
			else{
				if(prev==arr[i]){
					ans*=dp[cnt+2]; ans%=mod;
				}
				else{
					ans*=dp2[cnt+2]; ans%=mod;
					ans*=modpow(k-1,mod-2); ans%=mod;
				}
				prev = arr[i];
			}
			cnt = 0;
		}
	}
	if(prev>0){
		while(cnt>0){
			ans*=(k-1); ans%=mod;
			cnt--;
		}
	}
	else{
		cnt--;
		ans*=k;
		while(cnt>0){
			ans*=(k-1); ans%=mod;
			cnt--;
		}
	}
	cout << ans << "\n";
	return 0;
}