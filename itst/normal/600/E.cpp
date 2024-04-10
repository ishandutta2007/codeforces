#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
#define int long long
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
}Ed[MAXN << 1];
struct node{
	int l , r , maxN , sum;
}Tree[MAXN * 30];
int col[MAXN] , head[MAXN] , root[MAXN] , ans[MAXN] , N , cntEd , cntNode;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

inline void pushup(int x){
	Tree[x].maxN = max(Tree[Tree[x].l].maxN , Tree[Tree[x].r].maxN);
	Tree[x].sum = 0;
	if(Tree[x].maxN == Tree[Tree[x].l].maxN)
		Tree[x].sum += Tree[Tree[x].l].sum;
	if(Tree[x].maxN == Tree[Tree[x].r].maxN)
		Tree[x].sum += Tree[Tree[x].r].sum;
}

void insert(int& now , int l , int r , int tar){
	if(!now)
		now = ++cntNode;
	if(l == r){
		++Tree[now].maxN;
		Tree[now].sum = tar;
	}
	else{
		if(mid >= tar)
			insert(Tree[now].l , l , mid , tar);
		else
			insert(Tree[now].r , mid + 1 , r , tar);
		pushup(now);
	}
}

int merge(int p , int q , int l , int r){
	if(!p)
		return q;
	if(!q)
		return p;
	if(l == r){
		Tree[p].maxN += Tree[q].maxN;
		return p;
	}
	Tree[p].l = merge(Tree[p].l , Tree[q].l , l , mid);
	Tree[p].r = merge(Tree[p].r , Tree[q].r , mid + 1 , r);
	pushup(p);
	return p;
}

void dfs(int x , int p){
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs(Ed[i].end , x);
			root[x] = merge(root[x] , root[Ed[i].end] , 1 , N);
		}
	insert(root[x] , 1 , N , col[x]);
	ans[x] = Tree[root[x]].sum;
}

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		col[i] = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	dfs(1 , 0);
	for(int i = 1 ; i <= N ; ++i)
		printf("%lld " , ans[i]);
	return 0;
}