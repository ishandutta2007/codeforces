#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

lint gcd(lint x, lint y){ return y ? gcd(y, x%y) : x; }

int n;
vector<int> gph[MAXN];
lint a[MAXN], sum[MAXN];
int cnt[MAXN], tot[MAXN];
lint dp[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%lld",&a[i]);
		sum[i] = a[i];
	}
	for(int i=1; i<n; i++){
		int p; scanf("%d",&p);
		gph[p-1].push_back(i);
	}
	for(int i=n-1; i>=0; i--){
		for(auto &j : gph[i]){
			sum[i] += sum[j];
		}
	}
	for(int i=0; i<n; i++){
		lint v = gcd(sum[0], sum[i]);
		if(sum[0] / v > n) continue;
		cnt[sum[0] / v]++;
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j+=i){
			tot[j] += cnt[i];
		}
	}
	dp[1] = 1;
	lint ans = 0;
	for(int i=1; i<=n; i++){
		if(tot[i] == i){
			for(int j=i+i; j<=n; j+=i){
				dp[j] += dp[i];
				dp[j] %= mod;
			}
			ans += dp[i];
		}
	}
	cout << ans % mod;
}