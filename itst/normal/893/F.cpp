#include<bits/stdc++.h>
#define INF 0x7fffffff
#define mid ((l + r) >> 1)
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
struct node{
	int l , r , minN;
}Tree[MAXN * 30];
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
vector < int > num[MAXN];
int root[MAXN] , head[MAXN] , size[MAXN] , dfn[MAXN] , dep[MAXN] , val[MAXN];
int rt , T , N , M , cntEd , cntNode , maxD , ts;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs(int x , int p){
	dfn[x] = ++ts;
	dep[x] = dep[p] + 1;
	maxD = max(maxD , dep[x]);
	num[dep[x]].push_back(x);
	size[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs(Ed[i].end , x);
			size[x] += size[Ed[i].end];
		}
}

int insert(int now , int l , int r , int tar , int num){
	int x = ++cntNode;
	Tree[x] = Tree[now];
	Tree[x].minN = min(Tree[x].minN , num);
	if(l != r)
		if(mid >= tar)
			Tree[x].l = insert(Tree[x].l , l , mid , tar , num);
		else
			Tree[x].r = insert(Tree[x].r , mid + 1 , r , tar , num);
	return x;
}

int query(int root , int l , int r , int L , int R){
	if(!root)
		return INF;
	if(l >= L && r <= R)
		return Tree[root].minN;
	int minN = INF;
	if(mid >= L)
		minN = query(Tree[root].l , l , mid , L , R);
	if(mid < R)
		minN = min(minN , query(Tree[root].r , mid + 1 , r , L , R));
	return minN;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("893F.in" , "r" , stdin);
	//freopen("893F.out" , "w" , stdout);
#endif
	N = read();
	rt = read();
	Tree[0].minN = INF;
	for(int i = 1 ; i <= N ; ++i)
		val[i] = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	dfs(rt , 0);
	for(int i = 1 ; i <= maxD ; ++i){
		root[i] = root[i - 1];
		for(int j = 0 ; j < num[i].size() ; ++j)
			root[i] = insert(root[i] , 1 , N , dfn[num[i][j]] , val[num[i][j]]);
	}
	int lastans = 0;
	for(M = read() ; M ; --M){
		int a = (read() + lastans) % N + 1 , b = (read() + lastans) % N;
		printf("%d\n" , lastans = query(root[min(maxD , dep[a] + b)] , 1 , N , dfn[a] , dfn[a] + size[a] - 1));
	}
	return 0;
}