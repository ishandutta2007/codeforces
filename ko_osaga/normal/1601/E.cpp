#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 300005;
 
int n, q, k;
lint a[MAXN], val[MAXN];
lint minv[20][MAXN];
int nxt[20][MAXN];
lint dp[MAXN];
 
int find_first_smaller(int x, int y){
	if(x > n) return 1e9;
	if(minv[19][x] >= y) return 1e9;
	int ret = 0;
	for(int i = 18; i >= 0; i--){
		if(minv[i][x] >= y){
			ret += (1<<i);
			x += (1<<i) * k;
		}
	}
	return x;
}
 
lint shoot(int s, int x){
	if(s > n) return 0;
	int ffs = find_first_smaller(s, x);
	int len = (n - s) / k + 1;
	if(ffs > n) return 1ll * len * x;
	return dp[ffs] + 1ll * ((ffs - s) / k) * x;
}
 
lint query(int s, int e, int x){
	if(s > e) return 0;
	int len = (e - s) / k + 1;
	lint after_path = x;
	int pos = s;
	for(int i = 0; i < 20; i++){
		if((len >> i) & 1){
			after_path = min(after_path, minv[i][pos]);
			pos += (k << i);
		}
	}
	//printf("shoot(%d, %d) = %lld\n", s, x, shoot(s, x));
	//printf("shoot(%d, %d) = %lld\n", pos, after_path, shoot(pos, after_path));
	return shoot(s, x) - shoot(pos, after_path);
}
 
int main(){
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	scanf("%d %d %d",&n,&q,&k);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		pq.emplace(a[i], i);
		while(sz(pq) && pq.top().second <= i - k) pq.pop();
		val[i] = pq.top().first;
		minv[0][i] = val[i];
		nxt[0][i] = min(i + k, n + 1);
	}
	nxt[0][n + 1] = n + 1;
	minv[0][n + 1] = 2e9;
	for(int i = 1; i < 20; i++){
		for(int j = 1; j <= n+1; j++){
			minv[i][j] = min(minv[i-1][j], minv[i-1][nxt[i-1][j]]);
			nxt[i][j] = nxt[i-1][nxt[i-1][j]];
		}
	}
	for(int i = n; i; i--){
		dp[i] = shoot(i + k, val[i]) + val[i];
	}
	while(q--){
		int l, r; scanf("%d %d",&l,&r);
		lint ans = a[l] + query(l + k, r, a[l]);
		printf("%lld\n", ans);
	}
}