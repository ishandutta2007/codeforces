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

#define PII pair < int , int >
#define PIII pair < int , PII >
#define st first
#define nd second
#define ll long long
const int MAXN = 5e5 + 9;
struct node{
	ll minN , mark;
}Tree[MAXN << 2];
struct Edge{
	int end , upEd , w;
}Ed[MAXN];
vector < PIII > que[MAXN];
ll dep[MAXN] , ans[MAXN];
bool ifLeaf[MAXN];
int head[MAXN] , sz[MAXN] , cntEd , N , Q;

inline void addEd(int a , int b , int c){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	Ed[cntEd].w = c;
	head[a] = cntEd;
}

void dfs(int x){
	sz[x] = 1;
	ifLeaf[x] = !head[x];
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		dep[Ed[i].end] = dep[x] + Ed[i].w;
		dfs(Ed[i].end);
		sz[x] += sz[Ed[i].end];
	}
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
#define INF ((ll)1e18)
#define int long long
inline void pushup(int x){
	Tree[x].minN = min(Tree[lch].minN , Tree[rch].minN);
}

void init(int x , int l , int r){
	if(l == r)
		Tree[x].minN = ifLeaf[l] ? dep[l] : INF;
	else{
		init(lch , l , mid);
		init(rch , mid + 1 ,r);
		pushup(x);
	}
}

inline void mark(int x , int mrk){
	Tree[x].minN += mrk;
	Tree[x].mark += mrk;
}

inline void pushdown(int x){
	if(Tree[x].mark){
		mark(lch , Tree[x].mark);
		mark(rch , Tree[x].mark);
		Tree[x].mark = 0;
	}
}

void modify(int x , int l , int r , int L , int R , int mrk){
	if(l >= L && r <= R){
		mark(x , mrk);
		return;
	}
	pushdown(x);
	if(mid >= L)
		modify(lch , l , mid , L , R , mrk);
	if(mid < R)
		modify(rch , mid + 1 , r , L , R , mrk);
	pushup(x);
}

ll query(int x , int l , int r , int L , int R){
	if(Tree[x].minN > 1e15)
		return INF;
	if(l >= L && r <= R)
		return Tree[x].minN;
	pushdown(x);
	ll minN = INF;
	if(mid >= L)
		minN = min(minN , query(lch , l , mid , L , R));
	if(mid < R)
		minN = min(minN , query(rch , mid + 1 , r , L , R));
	return minN;
}

void solve(int x){
	for(int i = 0 ; i < que[x].size() ; ++i)
		ans[que[x][i].st] = query(1 , 1 , N , que[x][i].nd.st , que[x][i].nd.nd) + dep[x];
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		modify(1 , 1 , N , Ed[i].end , Ed[i].end + sz[Ed[i].end] - 1 , -Ed[i].w * 2);
		solve(Ed[i].end);
		modify(1 , 1 , N , Ed[i].end , Ed[i].end + sz[Ed[i].end] - 1 , Ed[i].w * 2);
	}
}

signed main(){
	N = read();
	Q = read();
	for(int i = 2 ; i <= N ; ++i){
		int a = read() , b = read();
		addEd(a , i , b);
	}
	for(int i = 1 ; i <= Q ; ++i){
		int p = read() , l = read() , r = read();
		que[p].push_back(PIII(i , PII(l , r)));
	}
	dfs(1);
	init(1 , 1 , N);
	solve(1);
	for(int i = 1 ; i <= Q ; ++i)
		cout << ans[i] << '\n';
	return 0;
}