#include<cstdio>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<queue>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 3e5 + 7 , MOD = 998244353;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , col[MAXN] , poww2[MAXN];
int N , M , cntEd , sz[2];

inline void addEd(int a , int b){
	Ed[++cntEd] = Edge{b , head[a]};
	head[a] = cntEd;
}

bool dfs(int x , int c){
	if(col[x] + 1 && col[x] != c)
		return 1;
	if(col[x] + 1)
		return 0;
	col[x] = c;
	++sz[c];
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(dfs(Ed[i].end , c ^ 1))
			return 1;
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	poww2[0] = 1;
	for(int i = 1 ; i <= 300000 ; ++i)
		poww2[i] = (poww2[i - 1] << 1) % MOD;
	for(int T = read() ; T ; --T){
		N = read();
		M = read();
		memset(head , 0 , sizeof(int) * (N + 1));
		memset(col , -1 , sizeof(int) * (N + 1));
		cntEd = 0;
		for(int i = 1 ; i <= M ; ++i){
			int a = read() , b = read();
			addEd(a , b);
			addEd(b , a);
		}
		bool f = 0;
		int ans = 1;
		for(int i = 1 ; !f && i <= N ; ++i)
			if(col[i] == -1){
				sz[0] = sz[1] = 0;
				if(dfs(i , 0))
					f = 1;
				else
					ans = 1ll * ans * (poww2[sz[0]] + poww2[sz[1]]) % MOD;
			}
		cout << (!f) * ans << endl;
	}
	return 0;
}