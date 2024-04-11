#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<pi> gph[88];
int n, k, m;
int dp[81][81][81][81];

int f(int c, int s, int e, int t){
	if(~dp[c][s][e][t]) return dp[c][s][e][t];
	if(t == 0) return 0;
	int ret = 1e9;
	for(auto &j : gph[c]){
		if(j.second > c && j.second <= e){
			ret = min(ret, f(j.second, j.second, e, t-1) + j.first);
			ret = min(ret, f(j.second, c+1, j.second, t-1) + j.first);
		}
		if(j.second < c && j.second >= s){
			ret = min(ret, f(j.second, s, j.second, t-1) + j.first);
			ret = min(ret, f(j.second, j.second, c-1, t-1) + j.first);
		}
	}
	return dp[c][s][e][t] = ret;
}

int main(){
	cin >> n >> k >> m;
	k--;
	for(int i=0; i<m; i++){
		int s, e, x;
		cin >> s >> e >> x;
		gph[s].push_back(pi(x, e));
	}
	memset(dp, -1, sizeof(dp));
	int ret = 1e9;
	for(int i=1; i<=n; i++){
		ret = min(ret, f(i, i, n, k));
		ret = min(ret, f(i, 1, i, k));
	}
	if(ret > 1e8) ret = -1;
	cout << ret;
}