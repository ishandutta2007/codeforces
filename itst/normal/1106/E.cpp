#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 7;
priority_queue < int , vector < int > , greater < int > > q;
struct line{
	int maxN , maxD;
}Tree[MAXN << 2];
int dp[MAXN][210] , N , M , K;

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
void modify(int x , int l , int r , int L , int R , int W , int D){
	if(l >= L && r <= R){
		if(Tree[x].maxN < W || Tree[x].maxN == W && Tree[x].maxD < D){
			Tree[x].maxN = W;
			Tree[x].maxD = D; 
		}
		return;
	}
	if(mid >= L)
		modify(lch , l , mid , L , R , W , D);
	if(mid < R)
		modify(rch , mid + 1 , r , L , R , W , D);
}

#define PII pair < int , int >
PII query(int x , int l , int r , int tar , int W , int D){
	if(Tree[x].maxN > W || Tree[x].maxN == W && Tree[x].maxD > D){
		W = Tree[x].maxN;
		D = Tree[x].maxD;
	}
	if(l == r)
		return PII(W , D);
	if(mid >= tar)
		return query(lch , l , mid , tar , W , D);
	return query(rch , mid + 1 , r , tar , W , D);
}

signed main(){
	N = read();
	M = read();
	for(int K = read() ; K ; --K){
		int s =read() , t = read() , d = read() , w = read();
		modify(1 , 1 , N , s , t , w , d);
	}
	int now = 0;
	memset(dp , 0x3f , sizeof(dp));
	dp[1][0] = 0;
	for(int i = 1 ; i <= N ; ++i){
		PII t = query(1 , 1 , N , i , 0 , 0);
		for(int j = 0 ; j < M ; ++j)
			dp[i + 1][j + 1] = min(dp[i][j] , dp[i + 1][j + 1]);
		if(t.first)
			for(int j = 0 ; j <= M ; ++j)
				dp[t.second + 1][j] = min(dp[t.second + 1][j] , dp[i][j] + t.first);
		else
			for(int j = 0 ; j <= M ; ++j)
				dp[i + 1][j] = min(dp[i][j] , dp[i + 1][j]);
	}
	int minN = 1e15;
	for(int i = 0 ; i <= M ; ++i)
		minN = min(minN , dp[N + 1][i]);
	cout << minN;
	return 0;
}