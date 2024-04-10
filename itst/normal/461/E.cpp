#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
int trs[_][4] , len[_] , fa[_] , cnt = 1 , lst = 1; char str[_]; long long N , L;

void ext(int l , int c){
	int t = ++cnt , p = lst; len[t] = l; lst = t;
	while(p && !trs[p][c]){trs[p][c] = t; p = fa[p];}
	if(!p){fa[t] = 1; return;}
	int q = trs[p][c]; if(len[q] == len[p] + 1){fa[t] = q; return;}
	int k = ++cnt; len[k] = len[p] + 1; memcpy(trs[k] , trs[q] , sizeof(trs[k]));
	fa[k] = fa[q]; fa[q] = fa[t] = k; while(trs[p][c] == q){trs[p][c] = k; p = fa[p];}
}

struct matrix{
	long long arr[4][4]; matrix(){memset(arr , 0x3f , sizeof(arr));}
	long long* operator [](int x){return arr[x];}
	friend matrix operator *(matrix p , matrix q){
		matrix x;
		for(int i = 0 ; i < 4 ; ++i)
			for(int j = 0 ; j < 4 ; ++j)
				for(int k = 0 ; k < 4 ; ++k)
					x[i][k] = min(x[i][k] , p[i][j] + q[j][k]);
		return x;
	}
}G , T;

int dp[_]; bool vis[_];
int solve(int p){
	if(vis[p]) return dp[p];
	for(int i = 0 ; i < 4 ; ++i)
		if(trs[p][i]) dp[p] = min(dp[p] , solve(trs[p][i]) + 1);
	vis[p] = 1; return dp[p];
}

int main(){
	scanf("%lld %s" , &N , str + 1); L = strlen(str + 1);
	for(int i = 1 ; i <= L ; ++i) ext(i , str[i] - 'A');
	for(int i = 0 ; i < 4 ; ++i){
		memset(dp , 0x3f , sizeof(dp)); memset(vis , 0 , sizeof(vis));
		for(int j = 1 ; j <= cnt ; ++j) if(!trs[j][i]) dp[j] = 1;
		for(int j = 0 ; j < 4 ; ++j) T[j][i] = solve(trs[1][j]);
	}
	long long L = 0 , R = 1e18;
	while(L < R){
		long long mid = (L + R + 1) >> 1 , t = mid; matrix temp = T;
		G = matrix(); G[0][0] = G[0][1] = G[0][2] = G[0][3] = 1;
		while(t){
			if(t & 1) G = G * temp;
			temp = temp * temp; t >>= 1;
		}
		bool flg = 0; for(int i = 0 ; i < 4 ; ++i) flg |= G[0][i] <= N;
		flg ? L = mid : R = mid - 1;
	}
	cout << L + 1; return 0;
}