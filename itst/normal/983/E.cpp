#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int __ = 2e5 + 3;
vector < int > ch[__];
int jump[__][19] , to[__][19] , dep[__] , dfn[__] , sz[__] , minP[__];
int ts , N , M , Q;

int dfs(int x){
	dfn[x] = ++ts; sz[x] = 1;
	for(auto t : ch[x]) sz[x] += dfs(t);
	return sz[x];
}

int LCA(int x , int y){
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 18 ; i >= 0 ; --i)
		if(dep[x] - (1 << i) >= dep[y])
			x = jump[x][i];
	if(x == y) return x;
	for(int i = 18 ; i >= 0 ; --i)
		if(jump[x][i] != jump[y][i]){
			x = jump[x][i]; y = jump[y][i];
		}
	return jump[x][0];
}

#define PII pair < int , int >
#define st first
#define nd second
vector < PII > route;
bool cmp(PII a , PII b){return dfn[a.st] < dfn[b.st];}

namespace segTree{
	const int _ = 5e6 + 3;
	int lch[_] , rch[_] , sum[_] , rt[__];
	int cntN;

#define mid ((l + r) >> 1)
	
	int modify(int x , int l , int r , int tar){
		int t = ++cntN; lch[t] = lch[x]; rch[t] = rch[x];
		sum[t] = sum[x] + 1;
		if(l == r) return t;
		if(mid >= tar) lch[t] = modify(lch[t] , l , mid , tar);
		else rch[t] = modify(rch[t] , mid + 1 , r , tar);
		return t;
	}

	int query(int x , int l , int r , int L , int R){
		if(L > R) return 0;
		if(l >= L && r <= R) return sum[x];
		int sum = 0;
		if(mid >= L) sum += query(lch[x] , l , mid , L , R);
		if(mid < R) sum += query(rch[x] , mid + 1 , r , L , R);
		return sum;
	}
	
	bool Query(int p , int q){
		return query(rt[dfn[p] + sz[p] - 1] , 1 , N , dfn[q] , dfn[q] + sz[q] - 1) - query(rt[dfn[p] - 1] , 1 , N , dfn[q] , dfn[q] + sz[q] - 1);
	}
	
	void build(){
		sort(route.begin() , route.end() , cmp);
		int pos = 0;
		for(int i = 1 ; i <= N ; ++i){
			rt[i] = rt[i - 1];
			while(pos < M && dfn[route[pos].st] == i)
				rt[i] = modify(rt[i] , 1 , N , dfn[route[pos++].nd]);
		}
	}
}

PII calc(int x , int p){
	int cnt = 0;
	for(int i = 17 ; i >= 0 ; --i)
		if(dep[to[x][i]] > dep[p]){
			cnt += 1 << i;
			x = to[x][i];
		}
	return PII(cnt + 1 , x);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	memset(minP , 0x3f , sizeof(minP));
	N = read();
	for(int i = 2 ; i <= N ; ++i)
		ch[jump[i][0] = read()].push_back(i);
	dfs(1);
	for(int i = 1 ; i <= N ; ++i){
		dep[i] = dep[jump[i][0]] + 1;
		for(int j = 1 ; jump[i][j - 1] ; ++j)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
	}
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		int x = read() , y = read() , t = LCA(x , y);
		minP[x] = min(minP[x] , t); minP[y] = min(minP[y] , t);
		if(dfn[x] > dfn[y]) swap(x , y);
		route.push_back(PII(x , y));
	}
	for(int i = N ; i ; --i)
		minP[jump[i][0]] = min(minP[jump[i][0]] , minP[i]);
	for(int i = 1 ; i <= N ; ++i){
		to[i][0] = min(minP[i] , i);
		for(int j = 1 ; j <= 18 ; ++j)
			to[i][j] = to[to[i][j - 1]][j - 1];
	}
	segTree::build();
	for(Q = read() ; Q ; --Q){
		int x = read() , y = read() , t = LCA(x, y);
		if(dfn[x] > dfn[y]) swap(x , y);
		if(dep[to[x][18]] > dep[t] || dep[to[y][18]] > dep[t]){
			puts("-1"); continue;
		}
		if(t == x)
			printf("%d\n" , calc(y , x).st);
		else{
			PII p = calc(x , t) , q = calc(y , t);
			printf("%d\n" , p.st + q.st - segTree::Query(p.nd , q.nd));
		}
	}
	return 0;
}