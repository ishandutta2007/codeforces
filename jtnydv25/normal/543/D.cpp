#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

const int N = 2e5 + 10;
int dp[N], dp2[N], ans[N];
int dp3[N];
vector<int> con[N];

void dfs(int s, int p){
	dp[s] = 1;
	int sz = con[s].size() + 1;
	if(s == 1) sz++;
	vector<int> vec(sz, 0);
	vector<int> vec2(sz, 1);
	vector<int> vec3(sz, 1);
	int iter = 1;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			vec[iter++] = v;
			dp[s] = mul(dp[s], 1 + dp[v]);
		}
	}
	int n = vec.size();
	for(int i = 1; i < n; i++) vec2[i] = mul(vec2[i - 1], dp[vec[i]] + 1);
	for(int i = n - 2; i >= 0; i--){
		vec3[i] = mul(vec3[i + 1], dp[vec[i]] + 1);
	}

	for(int i = 1; i <= n - 2; i++){
		dp3[vec[i]] = mul(vec2[i - 1], vec3[i + 1]);
	}
}

int root = 1;
void dfs2(int s, int p){
	if(s == root){
		dp2[s] = 0;
	}
	else{
		dp2[s] = mul(dp2[p] + 1, dp3[s]);
	}
	ans[s] = mul(dp[s], 1 + dp2[s]);
	for(int v : con[s]){
		if(v != p){
			dfs2(v, s);
		}
	}
}

int main(){
	int n;
	sd(n);
	for(int i = 2; i <= n; i++){
		int x;
		sd(x);
		con[x].push_back(i);
		con[i].push_back(x);
	}

	dfs(root, 0);
	dfs2(root, 0);
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
}