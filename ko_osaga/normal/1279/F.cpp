#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 1000005;

int n, k, l;
char str[MAXN];
int cnt[MAXN];

pi dp[MAXN];
int dq[MAXN];
int fr, ed;

pi trial(int f){
	fr = ed = 0;
	dq[ed++] = 0;
	for(int i=1; i<=n; i++){
		while(fr < ed && dq[fr] < i - l) fr++;
		dp[i] = dp[i-1];
		dp[i].first += cnt[i];
		if(i >= l && fr < ed){
			auto aux = dp[dq[fr]];
			aux.first += f;
			aux.second += 1;
			dp[i] = min(dp[i], aux);
		}
		while(fr + 1 < ed && dp[dq[ed - 1]] >= dp[i]) ed--;
		dq[ed++] = i;
	}
	return dp[n];
}

int solve(){
	if(1ll * k * l >= n) return 0;
	int s = 0, e = 1e6;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m).second <= k) e = m;
		else s = m + 1;
	}
	return trial(s).first - 1ll * k * s;
}

int main(){
	scanf("%d %d %d",&n,&k,&l);
	scanf("%s", str);
	for(int i=1; i<=n; i++){
		cnt[i] = 'A' <= str[i-1] && str[i-1] <= 'Z';
	}
	int ret = solve();
	for(int i=1; i<=n; i++){
		cnt[i] = 'a' <= str[i-1] && str[i-1] <= 'z';
	}
	ret = min(ret, solve());
	cout << ret << endl;
}