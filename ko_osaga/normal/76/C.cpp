#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int spt[18][200005];
int nxt[22][200005];
int lg[200005];
char str[200005];
int n, k, t;
int c1[22], c2[22][22];
lint dp[1<<22];

int query(int s, int e){
	if(s > e) return 0;
	int l = lg[e-s+1];
	return spt[l][s] | spt[l][e - (1<<l) + 1];
}

int main(){
	scanf("%d %d %d",&n,&k,&t);
	scanf("%s",str);
	for(int i=0; i<k; i++){
		scanf("%d",&c1[i]);
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			scanf("%d",&c2[i][j]);
		}
		nxt[i][n] = n;
	}
	int jc = 0;
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<k; j++){
			if(str[i] == j + 'A'){
				nxt[j][i] = i;
			}
			else nxt[j][i] = nxt[j][i+1];
		}
		spt[0][i] = (1 << (str[i] - 'A'));
		jc |= (1 << (str[i] - 'A'));
	}
	for(int i=1; i<=n; i++){
		lg[i] = lg[i-1];
		while((2 << lg[i]) <= i) lg[i]++;
	}
	for(int i=1; i<=17; i++){
		for(int j=0; j<n; j++){
			spt[i][j] = spt[i-1][j];
			if(j + (1<<(i-1)) < n) spt[i][j] |= spt[i-1][j + (1<<(i-1))];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			if(nxt[j][i+1] == n) continue;
			int bs = query(i+1, nxt[j][i+1] - 1);
			if((bs >> (str[i] - 'A')) & 1) continue;
			dp[bs] += c2[str[i] - 'A'][j];
			dp[bs | (1 << j)] -= c2[str[i] - 'A'][j];
			dp[bs | (1 << (str[i] - 'A'))] -= c2[str[i] - 'A'][j];
			dp[bs | (1 << j) | (1 << (str[i] - 'A'))] += c2[str[i] - 'A'][j];
		}
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<(1<<k); j++){
			if((j >> i) & 1){
				dp[j] += dp[j ^ (1<<i)];
			}
		}
	}
	int ret = 0;
	for(int i=0; i<(1<<k); i++){
		if(((~jc) & i)) continue;
		if(i == jc) continue;
		for(int j=0; j<k; j++){
			if((i >> j) & 1) dp[i] += c1[j];
		}
		if(dp[i] <= t){
		//	printf("%d %lld\n", i, dp[i]);
			ret++;
		}
	}
	cout << ret;
}