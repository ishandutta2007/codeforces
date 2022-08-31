#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, c[5005], d[5005], k, sz[5005];
vector<int> gph[5005];
	lint tmp[5005];

lint dp1[5005][5005], dp2[5005][5005];

void dfs(int x){
	sz[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
		sz[x] += sz[i];
	}
	dp1[x][0] = 0;
	dp1[x][1] = c[x];
	int cur = 1;
	for(auto &i : gph[x]){
		memset(tmp, 0x3f, sizeof(tmp));
		for(int j=0; j<=sz[i]; j++){
			for(int k=0; k<=cur; k++){
				tmp[j + k] = min(tmp[j + k], dp1[i][j] + dp1[x][k]);
			}
		}
		memcpy(dp1[x], tmp, sizeof(dp1[x]));
		cur += sz[i]; 
	}
	cur = 1;
	dp2[x][0] = 1e18;
	dp2[x][1] = d[x];
	for(auto &i : gph[x]){
		memset(tmp, 0x3f, sizeof(tmp));
		for(int j=0; j<=sz[i]; j++){
			for(int k=0; k<=cur; k++){
				tmp[j + k] = min(tmp[j + k], min(dp1[i][j], dp2[i][j]) + dp2[x][k]);
			}
		}
		memcpy(dp2[x], tmp, sizeof(dp2[x]));
		cur += sz[i];
	}
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> c[i] >> d[i];
		d[i] = c[i] - d[i];
		if(i > 1){
			int p;
			cin >> p;
			gph[p].push_back(i);
		}
	}
	dfs(1);
	for(int i=n; i>=0; i--){
		if(min(dp2[1][i], dp1[1][i]) <= k){
			cout << i << endl;
			return 0;
		}
	}
	assert(0);
}