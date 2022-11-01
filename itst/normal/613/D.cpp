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

const int MAXN = 100010;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1] , newEd[MAXN];
int head[MAXN] , jump[MAXN][20] , newHead[MAXN] , s[MAXN] , dfn[MAXN] , num[MAXN] , dp[MAXN][2] , dep[MAXN];
int N , headS , cntEd , cntNewEd , ts , cnt;
bool imp[MAXN];

inline void addEd(Edge* Ed , int* head , int& cntEd , int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void init(int now , int fa){
	dfn[now] = ++ts;
	dep[now] = dep[fa] + 1;
	jump[now][0] = fa;
	for(int i = 1 ; jump[now][i - 1] ; ++i)
		jump[now][i] = jump[jump[now][i - 1]][i - 1];
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa)
			init(Ed[i].end , now);
}

inline int jumpToLCA(int x , int y){
	if(dep[x] < dep[y])
		swap(x , y);
	for(int i = 19 ; i >= 0 ; --i)
		if(dep[x] - (1 << i) >= dep[y])
			x = jump[x][i];
	if(x == y)
		return x;
	for(int i = 19 ; i >= 0 ; --i)
		if(jump[x][i] != jump[y][i]){
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

inline void create(){
	imp[1] = 0;
	dp[1][0] = dp[1][1] = 0;
	for(int i = 1 ; i <= cnt ; ++i){
		imp[num[i]] = 1;
		dp[num[i]][1] = 0;
		dp[num[i]][0] = N + 1;
	}
	for(int i = 1 ; i <= cnt ; ++i)
		if(!headS)
			s[++headS] = num[i];
		else{
			int t = jumpToLCA(s[headS] , num[i]);
			if(t != s[headS]){
				while(dep[s[headS - 1]] > dep[t]){
					addEd(newEd , newHead , cntNewEd , s[headS - 1] , s[headS]);
					--headS;
				}
				addEd(newEd , newHead , cntNewEd , t , s[headS]);
				if(s[--headS] != t)
					s[++headS] = t;
			}
			s[++headS] = num[i];
		}
	while(headS - 1){
		addEd(newEd , newHead , cntNewEd , s[headS - 1] , s[headS]);
		--headS;
	}
	if(s[headS] != 1)
		addEd(newEd , newHead , cntNewEd , 1 , s[headS]);
	--headS;
}

void dfs(int now){
	int sum = 0;
	for(int i = newHead[now] ; i ; i = newEd[i].upEd){
		int t = newEd[i].end;
		dfs(t);
		if(imp[now])
			if(jump[t][0] == now)
				dp[now][1] += dp[t][0];
			else
				dp[now][1] += min(dp[t][0] , dp[t][1] + 1);
		else{
			if(jump[t][0] == now)
				dp[now][1] = min(sum + dp[t][1] , dp[now][1] + dp[t][0]);
			else
				dp[now][1] = min(sum + dp[t][1] , dp[now][1] + min(dp[t][0] , dp[t][1] + 1));
			if(jump[t][0] == now)
				sum += dp[t][0];
			else
				sum += min(dp[t][0] , dp[t][1] + 1);
		}
		if(dp[now][1] > N)
			dp[now][1] = N + 1;
		if(sum > N + 1)
			sum = N + 1;
	}
	sum = 0;
	for(int i = newHead[now] ; i ; i = newEd[i].upEd){
		int t = newEd[i].end;
		if(!imp[now]){
			sum += min(dp[t][0] , dp[t][1]);
			dp[now][0] += dp[t][0];
		}
		dp[t][0] = dp[t][1] = imp[t] = 0;
	}
	if(!imp[now])
		dp[now][0] = min(dp[now][0] , sum + 1);
	newHead[now] = 0;
}

bool cmp(int a , int b){
	return dfn[a] < dfn[b];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("613D.in" , "r" , stdin);
	//freopen("613D.out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(Ed , head , cntEd , a , b);
		addEd(Ed , head , cntEd , b , a);
	}
	init(1 , 0);
	for(int M = read() ; M ; --M){
		cnt = read();
		for(int i = 1 ; i <= cnt ; ++i)
			num[i] = read();
		sort(num + 1 , num + cnt + 1 , cmp);
		create();
		dfs(1);
		int t = min(dp[1][0] , dp[1][1]);
		printf("%d\n" , t == N + 1 ? -1 : t);
	}
	return 0;
}