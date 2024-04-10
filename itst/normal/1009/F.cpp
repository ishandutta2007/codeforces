#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1000010;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , dep[MAXN] , md[MAXN] , son[MAXN] , dyn[MAXN << 1] , ans[MAXN] , cntEd , N;
int *dp[MAXN] , *allo = dyn;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void init(int now , int fa){
	md[now] = dep[now] = dep[fa] + 1;
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa){
			init(Ed[i].end , now);
			if(md[Ed[i].end] > md[now]){
				md[now] = md[Ed[i].end];
				son[now] = Ed[i].end;
			}
		}
}

void dfs(int now , int fa){
	if(son[now]){
		dp[son[now]] = dp[now] + 1;
		dfs(son[now] , now);
		ans[now] = ans[son[now]] + 1;
	}
	dp[now][0] = 1;
	if(dp[now][ans[now]] == 1)
		ans[now] = 0;
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != son[now] && Ed[i].end != fa){
			dp[Ed[i].end] = allo;
			allo += (md[Ed[i].end] - dep[Ed[i].end] + 1) << 1;
			dfs(Ed[i].end , now);
			for(int j = 0 ; j <= md[Ed[i].end] - dep[Ed[i].end] ; ++j){
				dp[now][j + 1] += dp[Ed[i].end][j];
				if(dp[now][j + 1] > dp[now][ans[now]] || dp[now][j + 1] == dp[now][ans[now]] && j + 1 < ans[now])
					ans[now] = j + 1;
			}
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("1009F.in" , "r" , stdin);
	//freopen("1009F.out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	init(1 , 0);
	dp[1] = allo;
	allo += (md[1] - dep[1] + 1) << 1;
	dfs(1 , 0);
	for(int i = 1 ; i <= N ; ++i)
		printf("%d\n" , ans[i]);
	return 0;
}