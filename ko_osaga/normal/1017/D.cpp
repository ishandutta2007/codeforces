#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;

int n, m, q, w[22];
int cnt[1<<12], DC[1<<12];
int dap[1<<12][105];

int main(){
	cin >> n >> m >> q;
	for(int i=0; i<n; i++) cin >> w[i];
	char buf[15];
	for(int i=0; i<m; i++){
		scanf("%s", buf);
		int ans = 0;
		for(int j=0; j<n; j++){
			if(buf[j] & 1) ans |= (1<<j);
		}
		cnt[ans]++;
	}
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if((i >> j) % 2 == 0) DC[i] += w[j];
		}
	}
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<(1<<n); j++){
			int ans = DC[i ^ j];
			if(ans > 100) continue;
			dap[i][ans] += cnt[j];
		}
	}
	for(int i=0; i<(1<<n); i++){
		for(int j=1; j<=100; j++) dap[i][j] += dap[i][j-1];
	}
	while(q--){
		int k;
		scanf("%s %d",buf,&k);
		int ans = 0;
		for(int j=0; j<n; j++){
			if(buf[j] & 1) ans |= (1<<j);
		}
		printf("%d\n", dap[ans][k]);
	}
}