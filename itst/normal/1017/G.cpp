#include<bits/stdc++.h>
#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
#define st first
#define nd second
#define PII pair < int , int >
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
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 10;
struct node{
	int sum , maxN;
	bool mark;
}Tree[MAXN << 2];
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int N , Q , cntEd , ts;
int head[MAXN] , sz[MAXN] , top[MAXN] , dfn[MAXN] , fa[MAXN] , dep[MAXN] , son[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs1(int x , int p){
	fa[x] = p;
	dep[x] = dep[p] + 1;
	sz[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		dfs1(Ed[i].end , x);
		sz[x] += sz[Ed[i].end];
		if(sz[Ed[i].end] > sz[son[x]])
			son[x] = Ed[i].end;
	}
}

void dfs2(int x , int t){
	top[x] = t;
	dfn[x] = ++ts;
	if(!son[x])
		return;
	dfs2(son[x] , t);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != son[x])
			dfs2(Ed[i].end , Ed[i].end);
}

inline void mark(int x , int l , int r){
	Tree[x].mark = 1;
	Tree[x].sum = -(r - l + 1);
	Tree[x].maxN = -1;
}

inline void pushdown(int x , int l , int r){
	if(Tree[x].mark){
		mark(lch , l , mid);
		mark(rch , mid + 1 , r);
		Tree[x].mark = 0;
	}
}

inline void pushup(int x){
	Tree[x].sum = Tree[lch].sum + Tree[rch].sum;
	Tree[x].maxN = max(Tree[rch].maxN , Tree[rch].sum + Tree[lch].maxN);
}

void modify(int x , int l , int r , int L , int R){
	if(l >= L && r <= R){
		mark(x , l , r);
		return;
	}
	if(Tree[x].mark)
		return;
	if(mid >= L)
		modify(lch , l , mid , L , R);
	if(mid < R)
		modify(rch , mid + 1 , r , L , R);
	pushup(x);
}

void init(){
	N = read();
	Q = read();
	for(int i = 2 ; i <= N ; ++i)
		addEd(read() , i);
	dfs1(1 , 0);
	dfs2(1 , 1);
	modify(1 , 1 , N , 1 , N);
}

PII get(int x , int l , int r , int L , int R){
	if(l >= L && r <= R)
		return PII(Tree[x].maxN , Tree[x].sum);
	PII cur = PII(-0x7fffffff , 0) , a;
	pushdown(x , l , r);
	if(mid < R){
		a = get(rch , mid + 1 , r , L , R);
		cur.st = max(cur.st , a.st + cur.nd);
		cur.nd += a.nd;
	}
	if(mid >= L){
		a = get(lch , l , mid , L , R);
		cur.st = max(cur.st , a.st + cur.nd);
		cur.nd += a.nd;
	}
	return cur;
}

void add(int x , int l , int r , int tar , int num){
	if(l == r){
		Tree[x].maxN += num;
		Tree[x].sum += num;
		return;
	}
	pushdown(x , l , r);
	if(mid >= tar)
		add(lch , l , mid , tar , num);
	else
		add(rch , mid + 1 , r , tar , num);
	pushup(x);
}

inline int query(int x){
	PII cur = PII(-0x7fffffff , 0) , a;
	while(x){
		a = get(1 , 1 , N , dfn[top[x]] , dfn[x]);
		cur.st = max(cur.st , a.st + cur.nd);
		cur.nd += a.nd;
		x = fa[top[x]];
	}
	return cur.st;
}

void work(){
	int a;
	while(Q--)
		switch(read()){
		case 1:
			a = read();
			add(1 , 1 , N , dfn[a] , 1);
			break;
		case 2:
			a = read();
			modify(1 , 1 , N , dfn[a] , dfn[a] + sz[a] - 1);
			add(1 , 1 , N , dfn[a] , -1 - query(a));
			break;
		case 3:
			puts(query(read()) >= 0 ? "black" : "white");
		}
}

int main(){
	init();
	work();
	return 0;
}