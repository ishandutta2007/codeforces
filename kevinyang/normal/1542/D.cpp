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
	int n;
	cin >> n;
	vector<int>arr(n+1);
	int neg = 0;
	int pos = 0;
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		if(s=="+"){
			int x;
			cin >> x;
			pos++;
			arr[i] = x;
		}
		else{
			neg++;
		}
	}
	vector<pair<int,int>>sorted;
	sorted.push_back({0,0});
	for(int i = 1; i<=n; i++){
		if(arr[i]>0)sorted.push_back({arr[i],i});
	}
	sort(sorted.begin(),sorted.end());
	for(int i = 1; i<=n; i++){
		if(arr[i]>0){
			arr[i] = lower_bound(sorted.begin(),sorted.end(),make_pair(arr[i],i)) - sorted.begin();
		}
		//cout << arr[i] << " ";
	}
	//cout << "\n";
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(arr[i]==0)continue;
		vector<vector<int>>dp(n+5,vector<int>(n+5));
		dp[0][0] = 1;
		for(int a = 1; a<=n; a++){
			for(int b = 0; b<=n; b++){
				if(a<i){
					if(arr[a]==0){
						dp[a][b]+=dp[a-1][b+1];
						dp[a][b]+=dp[a-1][b];
						if(b==0)dp[a][b]+=dp[a-1][b];
						dp[a][b]%=mod;
					}
					else if(arr[a]>arr[i]){
						dp[a][b]+=dp[a-1][b]*2;
						dp[a][b]%=mod;
					}
					else{
						dp[a][b]+=dp[a-1][b];
						if(b>0)dp[a][b]+=dp[a-1][b-1];
						dp[a][b]%=mod;
					}
				}
				else if(a==i){
					if(b==0)continue;
					dp[a][b]+=dp[a-1][b-1];
					dp[a][b]%=mod;
				}
				else{
					if(arr[a]==0){
						if(b==0)continue;
						dp[a][b]+=dp[a-1][b+1];
						dp[a][b]+=dp[a-1][b];
						dp[a][b]%=mod;
					}
					else if(arr[a]>arr[i]){
						if(b==0)continue;
						dp[a][b]+=dp[a-1][b]*2;
						dp[a][b]%=mod;
					}
					else{
						if(b==0)continue;
						dp[a][b]+=dp[a-1][b];
						if(b>1)dp[a][b]+=dp[a-1][b-1];
						dp[a][b]%=mod;
					}
				}
			}
		}
		/*
		for(int a = 1; a<=n; a++){
			for(int b = 0; b<=n; b++){
				cout << dp[a][b] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		for(int a = 1; a<=n; a++){
			ans+=dp[n][a]*sorted[arr[i]].first; ans%=mod;
		}
		//cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}