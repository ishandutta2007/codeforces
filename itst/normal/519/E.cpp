#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 7;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int jump[MAXN][20] , dep[MAXN] , sz[MAXN] , head[MAXN];
int N , M , cntEd;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs(int x , int p){
	jump[x][0] = p;
	dep[x] = dep[p] + 1;
	sz[x] = 1;
	for(int i = 1 ; i <= 19 ; ++i)
		jump[x][i] = jump[jump[x][i - 1]][i - 1];
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs(Ed[i].end , x);
			sz[x] += sz[Ed[i].end];
		}
}

inline int LCA(int x , int y){
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

inline int jmp(int x , int stp){
	for(int i = 19 ; i >= 0 ; --i)
		if(stp & (1 << i))
			x = jump[x][i];
	return x;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	dfs(1 , 0);
	for(int Q = read() ; Q ; --Q){
		int l = read() , r = read();
		if((dep[l] + dep[r]) & 1)
			puts("0");
		else{
			int t = LCA(l , r) , mid = jmp(dep[l] > dep[r] ? l : r , (dep[r] + dep[l] - 2 * dep[t]) >> 1) , ans = 0;
			if(dep[l] == dep[r])
				ans = N - sz[jmp(l , (dep[r] + dep[l] - 2 * dep[t] >> 1) - 1)] - sz[jmp(r , (dep[r] + dep[l] - 2 * dep[t] >> 1) - 1)];
			else
				ans = sz[mid] - sz[jmp(dep[l] > dep[r] ? l : r , (dep[r] + dep[l] - 2 * dep[t] >> 1) - 1)];
			cout << ans << '\n';
		}
	}
	return 0;
}