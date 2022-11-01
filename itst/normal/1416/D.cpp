#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 5e5 + 7;
int N , M , Q , S[_] , T[_] , V[_] , op[_] , t[_] , ans[_]; bool vis[_];
int fa[_]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

#define mid ((l + r) >> 1)
const int __ = _ * 20; int sz[__] , ch[__][2] , cnt;
void ins(int &x , int l , int r , int t){
	if(!x) x = ++cnt;
	++sz[x]; if(l == r) return;
	mid >= t ? ins(ch[x][0] , l , mid , t) : ins(ch[x][1] , mid + 1 , r , t);
}

int qry(int x , int l , int r , int L){
	if(l >= L) return sz[x];
	return qry(ch[x][1] , mid + 1 , r , L) + (mid >= L ? qry(ch[x][0] , l , mid , L) : 0);
}

int findkth(int x , int l , int r , int k){
	if(l == r) return l;
	if(sz[ch[x][1]] >= k) return findkth(ch[x][1] , mid + 1 , r , k);
	return findkth(ch[x][0] , l , mid , k - sz[ch[x][1]]);
}

int merge(int p , int q){
	if(!p || !q) return p + q;
	int t = ++cnt; ch[t][0] = merge(ch[p][0] , ch[q][0]); ch[t][1] = merge(ch[p][1] , ch[q][1]);
	sz[t] = sz[p] + sz[q]; return t;
}

int son[_][2] , cnode , rt[_]; vector < int > qr[_];
void dfs(int x , int tofa){
	reverse(qr[x].begin() , qr[x].end()); int cfa = 0;
	if(tofa != N + 1) cfa = qry(rt[x] , 1 , N , tofa);
	for(int i = 0 ; i < qr[x].size() && cfa < sz[rt[x]] ; ++i , ++cfa)
		ans[qr[x][i]] = findkth(rt[x] , 1 , N , cfa + 1);
	if(x > N){
		int t = cfa == 0 ? N + 1 : findkth(rt[x] , 1 , N , cfa);
		dfs(son[x][0] , t); dfs(son[x][1] , t);
	}
}

int main(){
	N = read(); M = read(); Q = read();
	for(int i = 1 ; i <= N ; ++i) V[i] = read();
	for(int i = 1 ; i <= M ; ++i){S[i] = read(); T[i] = read();}
	for(int i = 1 ; i <= Q ; ++i){op[i] = read(); t[i] = read(); if(op[i] == 2) vis[t[i]] = 1;}
	cnode = N; for(int i = 1 ; i <= N ; ++i){fa[i] = i; ins(rt[i] , 1 , N , V[i]);}
	
	for(int i = 1 ; i <= M ; ++i)
		if(!vis[i] && find(S[i]) != find(T[i])){
			++cnode; int p = find(S[i]) , q = find(T[i]);
			rt[cnode] = merge(rt[p] , rt[q]); fa[cnode] = fa[p] = fa[q] = cnode;
			son[cnode][0] = p; son[cnode][1] = q;
		}
	
	for(int i = Q ; i ; --i)
		if(op[i] == 1) qr[find(t[i])].push_back(i);
		else if(find(S[t[i]]) != find(T[t[i]])){
			++cnode; int p = find(S[t[i]]) , q = find(T[t[i]]);
			rt[cnode] = merge(rt[p] , rt[q]); fa[cnode] = fa[p] = fa[q] = cnode;
			son[cnode][0] = p; son[cnode][1] = q;
		}
	for(int i = 1 ; i <= cnode ; ++i) if(fa[i] == i) dfs(i , N + 1);
	for(int i = 1 ; i <= Q ; ++i) if(op[i] == 1) printf("%d\n" , ans[i]);
	return 0;
}