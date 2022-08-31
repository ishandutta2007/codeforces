#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, prv[300005], prv2[2][300005], dp[300005];
lint a[2][300005];
map<pi, int> mp, dep;

void solve(){
	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		if(~prv[i]) dp[i] = max(dp[i], dp[prv[i]] + 1);
		int p1 = i, p2 = i, cnt = 0;
		vector<pi> v;
		while(~p1 && ~p2 && mp.find(pi(p1, p2)) == mp.end()){
			v.push_back(pi(p1, p2));
			if(prv2[0][p1] < prv2[1][p2]) p2 = prv2[1][p2];
			else p1 = prv2[0][p1];
		}
		if(mp.find(pi(p1, p2)) == mp.end()){
			tie(p1, p2) = v.back();
			v.pop_back();
			dep[pi(p1, p2)] = 0;
			mp[pi(p1, p2)] = dp[min(p1, p2)];
		}
		while(!v.empty()){
			dep[v.back()] = dep[pi(p1, p2)] + 1;
			mp[v.back()] = max(mp[pi(p1, p2)], 
					dp[min(v.back().first,v.back().second)] - dep[v.back()]);
			tie(p1, p2) = v.back();
			v.pop_back();
		}
		dp[i] = max(dp[i], mp[pi(p1, p2)] + dep[pi(p1, p2)]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<2; i++){
		for(int j=1; j<=n; j++){
			scanf("%lld",&a[i][j]);
			a[i][j] += a[i][j-1];
		}
	}
	map<lint, int> mp;
	mp[0] = 0;
	for(int i=1; i<=n; i++){
		if(mp.find(a[0][i] + a[1][i]) != mp.end()){
			prv[i] = mp[a[0][i] + a[1][i]];
		}
		else prv[i] = -1;
		mp[a[0][i] + a[1][i]] = i;
	}
	for(int i=0; i<2; i++){
		mp.clear();
		mp[0] = 0;
		prv2[i][0] = -1;
		for(int j=1; j<=n; j++){
			if(mp.find(a[i][j]) != mp.end()){
				prv2[i][j] = mp[a[i][j]];
			}
			else prv2[i][j] = -1;
			mp[a[i][j]] = j;
			prv2[i][j] = max(prv2[i][j], prv2[i][j-1]);
		}
	}
	solve();
	cout << dp[n];
}