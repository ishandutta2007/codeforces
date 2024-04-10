#include<bits/stdc++.h>
using namespace std;

const int _ = 503;
struct Edge{int end , upEd , w;}Ed[_ << 1];
int head[_] , cntEd , N , col[_] , X , num;
short dp[_][_][_] , sz[_]; bool ban[_][_];
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

void dist(int x , int p , long long l , int r){
	if(l > X) ban[x][r] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) dist(Ed[i].end , x , l + Ed[i].w , r);
}

int dfn[_] , ts;
void dfs1(int x , int p){
	dfn[x] = ++ts;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) dfs1(Ed[i].end , x);
}

void dfs(int x , int p){
	sz[x] = 1; for(int i = 1 ; i <= N ; ++i){dp[x][1][dfn[i]] = 16383; if(ban[x][i]) dp[x][0][dfn[i]] = 16383;}
	if(col[x]){dp[x][0][dfn[x]] = 1; dp[x][1][dfn[x]] = 16383;} else{dp[x][1][dfn[x]] = 1; dp[x][0][dfn[x]] = 16383;}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			int t = Ed[i].end; dfs(t , x);
			static short tmp[_][_]; memset(tmp , 0x3f , sizeof(tmp));
			for(int j = 0 ; j <= sz[t] ; ++j){
				short mn = 16383;
				for(int k = dfn[t] ; k < dfn[t] + sz[t] ; ++k)
					mn = min(mn , dp[t][j][k]);
				for(int i = 0 ; i <= sz[x] ; ++i)
					for(int k = 1 ; k <= N ; ++k){
						tmp[i + j][k] = min(tmp[i + j][k] , (short)(dp[x][i][k] + dp[t][j][k]));
						if(!(k >= dfn[t] && k < dfn[t] + sz[t]))
							tmp[i + j][k] = min(tmp[i + j][k] , (short)(dp[x][i][k] + mn));
					}
			}
			sz[x] += sz[t]; memcpy(dp[x] , tmp , sizeof(tmp));
		}
}

int main(){
	cin >> N >> X; for(int i = 1 ; i <= N ; ++i){cin >> col[i]; num += col[i];}
	for(int i = 1 ; i < N ; ++i){int a , b , c; cin >> a >> b >> c; addEd(a , b , c); addEd(b , a , c);}
	for(int i = 1 ; i <= N ; ++i) dist(i , 0 , 0 , i);
	dfs1(1 , 0); dfs(1 , 0);
	for(int i = 0 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			if(num >= dp[1][i][j]){cout << i; return 0;}
	cout << -1;
	return 0;
}