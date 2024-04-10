#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = 998244353;
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
vector<pair<int,int>>arr(105);
int dist(int i,int j){
	pair<int,int>a = arr[i];
	pair<int,int>b = arr[j];
	return abs(a.first-b.first)+abs(a.second-b.second);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y};
	}
	vector<int>freq(n+1);
	vector<int>val(n+1);
	for(int i = 1; i<=n; i++){
		int mn = (int)1e9;
		for(int j = 1; j<=n; j++){
			if(j==i)continue;
			mn = min(mn,dist(i,j));
		}
		for(int j = 1; j<=n; j++){
			if(j==i)continue;
			if(dist(i,j)==mn){
				freq[i]++;
			}
		}
		val[i] = mn;
	}
	vector<int>cnt(5);
	//groups of size 1, 2, 3 and 4	
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			if(val[i]==val[j]&&freq[i]==1&&freq[j]==1&&dist(i,j)==val[i]){
				cnt[2]++;
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			for(int k = j+1; k<=n; k++){
				if(val[i]==val[j]&&val[i]==val[k]&&freq[i]==2&&freq[j]==2&&freq[k]==2){
					if(dist(i,j)==dist(i,k)&&dist(i,j)==dist(j,k)&&dist(i,j)==val[i]){
						cnt[3]++;
					}
				}
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			for(int k = j+1; k<=n; k++){
				for(int l = k+1; l<=n; l++){
					if(val[i]==val[j]&&val[j]==val[k]&&val[k]==val[l]&&freq[i]==3&&freq[j]==3&&freq[k]==3&&freq[l]==3){
						int a = dist(i,j);
						int b = dist(i,k);
						int c = dist(i,l);
						int d = dist(j,k);
						int e = dist(j,l);
						int f = dist(k,l);
						if(a==b&&b==c&&c==d&&d==e&&e==f&&f==val[i]){
							cnt[4]++;
						}
					}
				}
			}
		}
	}
	cnt[1] = n-2*cnt[2]-3*cnt[3]-4*cnt[4];
	int m = cnt[1]+cnt[2]+cnt[3]+cnt[4];
	//cout << m << "\n";
	vector<int>a;
	a.push_back(0);
	for(int j = 1; j<=4; j++){
		for(int i = 0; i<cnt[j]; i++){
			a.push_back(j);
			//cout << j << "\n";
		}
	}
	vector<vector<int>>dp(m+1,vector<int>(n+1));
	dp[0][0] = 1;
	for(int t = 1; t<=m; t++){
		for(int i = 1; i<=n; i++){
			dp[t][i]+=dp[t-1][i-1];
			dp[t][i]%=mod;
		}
		if(a[t]!=1)for(int i = a[t]; i<=n; i++){
			dp[t][i]+=dp[t-1][i-a[t]];
			dp[t][i]%=mod;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		//cout << dp[m][i] << " ";
		ans+=dp[m][i]*permute(n,i)%mod;
		ans%=mod;
	}
	cout << ans << "\n";
	return 0;
}