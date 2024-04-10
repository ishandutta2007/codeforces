#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , MOD = 1e9 + 7;
void inc(int &a , int b){a = (a + b) % MOD;}
struct Edge{int end , upEd , w1 , w2;}Ed[_ << 1];
int head[_] , N , M , cntEd = 1;
void addEd(int a , int b , int c , int d){Ed[++cntEd] = (Edge){b , head[a] , c , d}; head[a] = cntEd;}

bool vis[_];
int dfs1(int x){
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){int t = dfs1(Ed[i].end); vis[x] = 0; return t;}
	vis[x] = 0; return x;
}

int dp[_][2][2][2] , all[2] , tmp[2][2][2] , lst;
void dfs2(int x , int pi){
	lst = x; vis[x] = 1; bool flg[2] = {}; if(!pi) dp[x][0][0][0] = dp[x][1][1][0] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd) if(Ed[i].end == x) flg[Ed[i].w1] ^= 1;
	if(flg[1]){swap(dp[x][0][0][0] , dp[x][0][0][1]); swap(dp[x][1][0][0] , dp[x][1][0][1]);}
	if(flg[0]){swap(dp[x][0][1][0] , dp[x][0][1][1]); swap(dp[x][1][1][0] , dp[x][1][1][1]);}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(i != pi && Ed[i].end != x)
			if(vis[Ed[i].end]){
				memset(tmp , 0 , sizeof(tmp));
				for(int p = 0 ; p < 2 ; ++p)
					for(int q = 0 ; q < 2 ; ++q)
						for(int r = 0 ; r < 2 ; ++r)
							inc(tmp[p][q][r ^ ((q ^ Ed[i].w1) | (p ^ Ed[i].w2))] , dp[x][p][q][r]);
				memcpy(dp[x] , tmp , sizeof(tmp));
			}
			else{
				for(int p = 0 ; p < 2 ; ++p)
					for(int q = 0 ; q < 2 ; ++q)
						for(int r = 0 ; r < 2 ; ++r)
							for(int s = 0 ; s < 2 ; ++s)
								inc(dp[Ed[i].end][p][s][r ^ ((q ^ Ed[i].w1) | (s ^ Ed[i].w2))] , dp[x][p][q][r]);
				dfs2(Ed[i].end , i ^ 1);
			}
}

int main(){
	cin >> M >> N; all[0] = 1;
	for(int i = 1 ; i <= M ; ++i){
		int k , x1 , x2; cin >> k >> x1; if(k == 1) x2 = x1; else cin >> x2;
		if(x1 == -x2){swap(all[0] , all[1]); continue;}
		addEd(abs(x1) , abs(x2) , x1 < 0 , x2 < 0);
		if(x1 != x2) addEd(abs(x2) , abs(x1) , x2 < 0 , x1 < 0);
		else addEd(0 , 0 , 0 , 0);
	}
	for(int i = 1 ; i <= N ; ++i)
		if(!vis[i]){
			dfs2(dfs1(i) , 0); int x = all[0] , y = all[1] , s1 = 0 , s2 = 0;
			for(int p = 0 ; p < 2 ; ++p)
				for(int q = 0 ; q < 2 ; ++q){inc(s1 , dp[lst][p][q][0]); inc(s2 , dp[lst][p][q][1]);}
			all[0] = (1ll * x * s1 + 1ll * y * s2) % MOD;
			all[1] = (1ll * x * s2 + 1ll * y * s1) % MOD;
		}
	cout << all[1]; return 0;
}