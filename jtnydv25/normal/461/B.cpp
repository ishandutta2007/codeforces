#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
const int N = 1e5 +  10;
int dp[2][N], col[N];
vector<int> con[N];
void dfs(int s, int p){
	int f0[2] = {0, 0}; 
	int f1[2] = {0, 0};
	f0[col[s]] = 1;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			memcpy(f1, f0, sizeof f0);
			memset(f0, 0, sizeof f0);
			// v -> 0
			//or
			// v-> 1
			// cut
			for(int i = 0; i < 2; i++)
				f0[i] = add(f0[i], mul(f1[i], add(dp[1][v], dp[0][v])));
			// v->1
			//don't cut
			f0[1] = add(f0[1], mul(f1[0], dp[1][v]));
		}
	}
	dp[0][s] = f0[0];
	dp[1][s] = f0[1];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u;
		scanf("%d", &u);
		con[i + 1].push_back(u + 1);
		con[u + 1].push_back(i + 1);
	}
	for(int i = 1; i <= n;i++) scanf("%d", col + i);
	dfs(1, 0);
	printf("%d\n", dp[1][1]);
}