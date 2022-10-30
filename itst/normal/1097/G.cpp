#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 1e5 + 3 , MOD = 1e9 + 7;
struct Edge{
	int end , upEd;
}Ed[_ << 1];
int head[_] , ans[207] , dp[_][207] , tmp[207] , S[207][207] , sz[_] , N , K , cntEd;

void addEd(int a , int b){
	Ed[++cntEd] = (Edge){b , head[a]};
	head[a] = cntEd;
}

void dfs(int x , int p){
	dp[x][0] = 1; sz[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs(Ed[i].end , x); memset(tmp , 0 , sizeof(tmp));
			for(int j = 0 ; j < sz[x] && j <= K ; ++j)
				for(int k = 0 ; j + k <= K && k < sz[Ed[i].end] ; ++k){
					int val = 1ll * dp[x][j] * dp[Ed[i].end][k] % MOD;
					ans[j + k] = (ans[j + k] + val) % MOD;
					ans[j + k + 1] = (ans[j + k + 1] + val) % MOD;
					tmp[j + k] = (tmp[j + k] + val) % MOD;
					tmp[j + k + 1] = (tmp[j + k + 1] + val) % MOD;
				}
			for(int j = 0 ; j <= K ; ++j)
				dp[x][j] = (0ll + dp[x][j] + tmp[j] + dp[Ed[i].end][j] + (j ? dp[Ed[i].end][j - 1] : 0)) % MOD;
			sz[x] += sz[Ed[i].end];
		}
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); K = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b); addEd(b , a);
	}
	dfs(1 , 0); S[1][1] = 1;
	for(int i = 2 ; i <= K ; ++i)
		for(int j = 1 ; j <= i ; ++j)
			S[i][j] = (1ll * S[i - 1][j] * j + S[i - 1][j - 1]) % MOD;
	int sum = 0 , times = 1;
	for(int i = 1 ; i <= K ; ++i){
		times = 1ll * times * i % MOD;
		sum = (sum + 1ll * ans[i] * times % MOD * S[K][i]) % MOD;
	}
	cout << sum;
	return 0;
}