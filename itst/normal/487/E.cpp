#include<bits/stdc++.h>
#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
#define INF 0x7fffffff
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

const int MAXN = 2e5 + 7;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , val[MAXN] , N , M , Q , cntEd , cnt;
int topS , ts , st[MAXN] , dfn[MAXN] , low[MAXN];
int ind[MAXN] , rk[MAXN] , fa[MAXN] , dep[MAXN] , son[MAXN] , sz[MAXN] , top[MAXN] , TS;
int Tree[MAXN << 2];
bool vis[MAXN];
vector < int > ch[MAXN];
multiset < int > s[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

inline void pop(int t , int bot){
	ch[t].push_back(++cnt);
	do{
		ch[cnt].push_back(st[topS]);
		s[cnt].insert(val[st[topS]]);
	}while(st[topS--] != bot);
}

void tarjan(int x , int p){
	st[++topS] = x;
	dfn[x] = low[x] = ++ts;
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			if(!vis[Ed[i].end]){
				tarjan(Ed[i].end , x);
				low[x] = min(low[x] , low[Ed[i].end]);
				if(low[Ed[i].end] >= dfn[x])
					pop(x , Ed[i].end);
			}
			else
				low[x] = min(low[x] , dfn[Ed[i].end]);
}

void dfs1(int x , int p){
	fa[x] = p;
	dep[x] = dep[p] + 1;
	sz[x] = 1;
	for(int i = 0 ; i < ch[x].size() ; ++i){
		dfs1(ch[x][i] , x);
		sz[x] += sz[ch[x][i]];
		if(sz[son[x]] < sz[ch[x][i]])
			son[x] = ch[x][i];
	}
}

void dfs2(int x , int t){
	ind[x] = ++TS;
	rk[TS] = x;
	top[x] = t;
	if(!son[x])
		return;
	dfs2(son[x] , t);
	for(int i = 0 ; i < ch[x].size() ; ++i)
		if(ch[x][i] != son[x])
			dfs2(ch[x][i] , ch[x][i]);
}

inline void pushup(int x){
	Tree[x] = min(Tree[lch] , Tree[rch]);
}

void init(int x , int l , int r){
	if(l == r)
		Tree[x] = rk[l] <= N ? val[rk[l]] : *s[rk[l]].begin();
	else{
		init(lch , l , mid);
		init(rch , mid + 1 , r);
		pushup(x);
	}
}

void modify(int x , int l , int r , int tar , int num){
	if(l == r)
		Tree[x] = num;
	else{
		if(mid >= tar)
			modify(lch , l , mid , tar , num);
		else
			modify(rch , mid + 1 , r , tar , num);
		pushup(x);
	}
}

int query(int x , int l , int r , int L , int R){
	if(l >= L && r <= R)
		return Tree[x];
	int minN = INF;
	if(mid >= L)
		minN = min(minN , query(lch , l , mid , L , R));
	if(mid < R)
		minN = min(minN , query(rch , mid + 1 , r , L , R));
	return minN;
}

int work(int x , int y){
	int tx = top[x] , ty = top[y] , minN = INF;
	while(tx != ty){
		if(dep[tx] < dep[ty]){
			swap(x , y);
			swap(tx , ty);
		}
		minN = min(minN , query(1 , 1 , cnt , ind[tx] , ind[x]));
		x = fa[tx];
		tx = top[x];
	}
	if(dep[x] > dep[y])
		swap(x , y);
	minN = min(minN , query(1 , 1 , cnt , ind[x] , ind[y]));
	if(x > N)
		minN = min(minN , val[fa[x]]);
	return minN;
}

inline char getc(){
	char c = getchar();
	while(!isupper(c))
		c = getchar();
	return c;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cnt = N = read();
	M = read();
	Q = read();
	for(int i = 1 ; i <= N ; ++i)
		val[i] = read();
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	tarjan(1 , 0);
	dfs1(1 , 0);
	dfs2(1 , 1);
	init(1 , 1 , cnt);
	while(Q--)
		if(getc() == 'A')
			printf("%d\n" , work(read() , read()));
		else{
			int a = read() , b = read();
			if(a != 1){
				s[fa[a]].erase(s[fa[a]].find(val[a]));
				s[fa[a]].insert(b);
				modify(1 , 1 , cnt , ind[fa[a]] , *s[fa[a]].begin());
			}
			val[a] = b;
			modify(1 , 1 , cnt , ind[a] , b);
		}
	return 0;
}