#include<bits/stdc++.h>
#define INF 0x7fffffff
#define lch Tree[x].l
#define rch Tree[x].r
#define mid ((l + r) >> 1)
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

const int MAXN = 3e5 + 10;
struct node{
	int l , r , maxN;
}Tree[MAXN * 30];
struct seg{
	int l , r , be;
	friend bool operator <(seg a , seg b){
		return a.l > b.l;
	}
}now[MAXN];
int root[MAXN] , be[MAXN] , l[MAXN] , N , M , K , cntNode , cnt;

inline int max(int a , int b){
	return a > b ? a : b;
}

inline int min(int a , int b){
	return a < b ? a : b;
}

inline void pushup(int x){
	if(!lch || !rch)
		Tree[x].maxN = INF;
	else
		Tree[x].maxN = max(Tree[lch].maxN , Tree[rch].maxN);
}

int modify(int x , int l , int r , int tar , int num){
	int t = ++cntNode;
	Tree[t] = Tree[x];
	x = t;
	if(l == r){
		if(!Tree[t].maxN || Tree[t].maxN > num)
			Tree[t].maxN = num;
		return t;
	}
	if(mid >= tar)
		lch = modify(lch , l , mid , tar , num);
	else
		rch = modify(rch , mid + 1 , r , tar , num);
	pushup(x);
	return x;
}

int query(int x , int l , int r , int L , int R){
	if(!x)
		return INF;
	if(l >= L && r <= R)
		return Tree[x].maxN;
	int maxN = 0;
	if(mid >= L)
		maxN = query(lch , l , mid , L , R);
	if(mid < R)
		maxN = max(query(rch , mid + 1 , r , L , R) , maxN);
	return maxN;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	M = read();
	K = read();
	for(int i = 1 ; i <= K ; ++i){
		now[i].l = read();
		now[i].r = read();
		now[i].be = read();
	}
	sort(now + 1 , now + K + 1);
	for(int i = 1 ; i <= K ; ++i){
		if(i == 1 || now[i].l != now[i - 1].l){
			++cnt;
			root[cnt] = root[cnt - 1];
		}
		be[i] = cnt;
		l[i] = now[i].l;
		root[cnt] = modify(root[cnt] , 1 , N , now[i].be , now[i].r);
	}
	reverse(be + 1 , be + K + 1);
	reverse(l + 1 , l + K + 1);
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read() , x = read() , y = read();
		int k = lower_bound(l + 1 , l + K + 1 , x) - l;
		puts(query(root[be[k]] , 1 , N , a , b) <= y ? "yes" : "no");
		fflush(stdout);
	}
	return 0;
}