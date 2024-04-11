#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const int mod = 1e9 + 7;
typedef pair<int, int> pi;
typedef long long lint;

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv;
		piv = piv * piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

int n, m, k;
vector<int> ptr;
vector<pi> v1, v2;
int max1[MAXN], max2[MAXN];

int getloc(int x){
	return lower_bound(ptr.begin(), ptr.end(), x) - ptr.begin();
}

lint dp[MAXN][3][3], sum[MAXN][3][3];
lint pwr[MAXN], dpdp[MAXN];

int main(){
	scanf("%d %d %d",&k,&n,&m);
	ptr.push_back(0);
	ptr.push_back(k);
	int s, e;
	for(int i=0; i<n; i++){
		scanf("%d %d",&s,&e);
		v1.emplace_back(s, e);
	}
	for(int i=0; i<m; i++){	
		scanf("%d %d",&s,&e);
		v2.emplace_back(s, e);
	}
	for(auto &i : v1) ptr.push_back(i.first - 1), ptr.push_back(i.second);
	for(auto &i : v2) ptr.push_back(i.first - 1), ptr.push_back(i.second);
	sort(ptr.begin(), ptr.end());
	ptr.resize(unique(ptr.begin(), ptr.end()) - ptr.begin());
	memset(max1, -1, sizeof(max1));
	memset(max2, -1, sizeof(max2));
	for(auto &i : v1){
		int l = getloc(i.first - 1);
		int r = getloc(i.second);
		max1[r] = max(max1[r], l);
	}
	for(auto &i : v2){
		int l = getloc(i.first - 1);
		int r = getloc(i.second);
		max2[r] = max(max2[r], l);
	}
	for(int i=1; i<=ptr.size(); i++){
		max1[i] = max(max1[i], max1[i-1]);
		max2[i] = max(max2[i], max2[i-1]);
		if(i != ptr.size()) pwr[i] = ipow(2, ptr[i] - ptr[i-1]) + mod - 2;
		pwr[i] %= mod;
	}
	dp[0][1][2] = sum[0][1][2] = 1;
	dp[0][2][0] = sum[0][2][0] = 1;
	dp[0][0][1] = sum[0][0][1] = 1;
	dpdp[0] = 1;
	auto gs = [&](int x, int l, int r){
		lint ans = 0;
		for(int i=0; i<3; i++){
			ans += sum[r][i][x] - (l ? sum[l-1][i][x] : 0) + mod;
		}
		return ans % mod;
	};
	for(int i=1; i<ptr.size(); i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(j == k) continue;
				if(j == 0){
					dp[i][j][k] = gs(j, max1[i] + 1, i - 1);
				}
				if(j == 1){
					dp[i][j][k] = gs(j, max2[i] + 1, i - 1);
				}
				if(j == 2){
					lint tmp = dpdp[i-1] * pwr[i] % mod;
					dp[i][j][k] = tmp;
					/*
					for(int l=i-1; l>=0; l--){
						lint val = dp[l][0][j] + dp[l][1][j] + dp[l][2][j];
						val %= mod;
						tmp *= pwr[l+1];
						tmp %= mod;
						dp[i][j][k] += val * tmp % mod;
					}
					dp[i][j][k] %= mod;*/
				}
				sum[i][j][k] = sum[i-1][j][k] + dp[i][j][k];
			}
		}
		dpdp[i] = dpdp[i-1] * pwr[i] % mod + (dp[i][0][2] + dp[i][1][2] + dp[i][2][2]);
		dpdp[i] %= mod;
	}
	lint ans = 0;
	for(int i=0; i<3; i++) ans += dp[ptr.size()-1][i][(i+1)%3];
	ans %= mod;
	cout << ans << endl;
}