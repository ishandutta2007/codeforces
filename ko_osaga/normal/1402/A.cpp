// shirley smokes weed
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 400;

int n, m, s[MAXN], e[MAXN], x[MAXN];
int dp[1 << 18], indep[1 << 18], w[1 << 18], tk[1 << 18];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		scanf("%d %d %d",&s[i],&e[i],&x[i]);
		s[i]--; e[i]--;
	}
	for(int i=1; i<(1<<n); i++){
		indep[i] = 1;
		for(int j=0; j<m; j++){
			int b1 = (i >> s[j]) & 1;
			int b2 = (i >> e[j]) & 1;
			if(b1 && b2) indep[i] = 0;
			if(b1 == b2) continue;
			if(b1 == 1 && b2 == 0) w[i] = 1e9;
			else w[i] += x[j];
		}
	}
	dp[0] = 0;
	for(int i=1; i<(1<<n); i++){
		dp[i] = 1e9;
		if(w[i] > 1e8) continue;
		for(int j=i; j; j=(j-1)&i){
			if(indep[j] && dp[i] > dp[i ^ j]){
				dp[i] = dp[i ^ j];
				tk[i] = j;
			}
		}
		dp[i] += w[i];
	}
	vector<int> a(n);
	for(int i = (1 << n) - 1; i; i ^= tk[i]){
		for(int j = 0; j < n; j++){
			if((i >> j) & 1) a[j]++;
		}
	}
	for(int i=0; i<n; i++) printf("%d ", n + 1 - a[i]);
}