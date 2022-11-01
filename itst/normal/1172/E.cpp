#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define ll long long
ll pw(int x){return 1ll * x * x;}
const int _ = 5e5 + 7; vector < int > nxt[_]; int N , M , tfa[_] , tsz[_] , col[_]; vector < pair < int , int > > mdf[_]; ll tsum[_] , ans[_];
void dfs(int x , int p){tfa[x] = p; tsz[x] = 1; for(auto t : nxt[x]) if(t != p){dfs(t , x); tsz[x] += tsz[t]; tsum[x] += pw(tsz[t]);}}

int ch[_][2] , fa[_] , sz[_] , lsz[_]; ll lsum[_] , val;
bool nroot(int x){return ch[fa[x]][0] == x || ch[fa[x]][1] == x;}
bool son(int x){return ch[fa[x]][1] == x;}
void upd(int x){sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + lsz[x] + 1;}
void rot(int x){
	bool f = son(x); int y = fa[x] , z = fa[y] , w = ch[x][f ^ 1];
	fa[x] = z; if(nroot(y)) ch[z][son(y)] = x;
	fa[y] = x; ch[x][f ^ 1] = y; ch[y][f] = w; if(w) fa[w] = y;
	upd(y);
}
void splay(int x){while(nroot(x)){if(nroot(fa[x])){rot(son(fa[x]) == son(x) ? fa[x] : x);} rot(x);} upd(x);}

void access(int x){
	for(int y = 0 ; x ; y = x , x = fa[x]){
		splay(x); lsz[x] += sz[ch[x][1]] - sz[y];
		lsum[x] += pw(sz[ch[x][1]]) - pw(sz[y]); ch[x][1] = y;
	}
}
int fdrt(int x){access(x); splay(x); while(ch[x][0]){x = ch[x][0];} splay(x); return x;}
void cut(int x){
	int allsz = sz[ch[fdrt(x)][1]]; splay(x);
	val = val - pw(allsz) + pw(allsz - lsz[x] - sz[ch[x][1]] - 1) + lsum[x] + pw(sz[ch[x][1]]);
	ch[x][0] = fa[ch[x][0]] = 0; upd(x);
}
void link(int x){
	int f = tfa[x] , upsz = sz[ch[fdrt(f)][1]]; splay(x); splay(f);
	val = val - lsum[x] - pw(sz[ch[x][1]]) - pw(upsz) + pw(sz[x] + upsz);
	fa[x] = f; lsz[f] += sz[x]; sz[f] += sz[x]; lsum[f] += pw(sz[x]);
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= N ; ++i){col[i] = read(); mdf[col[i]].push_back(make_pair(0 , i));}
	for(int i = 1 ; i < N ; ++i){int p = read() , q = read(); nxt[p].push_back(q); nxt[q].push_back(p);}
	nxt[N + 1] = {1}; dfs(N + 1 , 0); for(int i = 1 ; i <= N + 1 ; ++i){fa[i] = tfa[i]; sz[i] = tsz[i]; lsz[i] = tsz[i] - 1; lsum[i] = tsum[i];}
	for(int i = 1 ; i <= M ; ++i){int p = read() , q = read(); mdf[col[p]].push_back(make_pair(i , -p)); mdf[col[p] = q].push_back(make_pair(i , p));}
	val = pw(N);
	
	for(int i = 1 ; i <= N ; ++i){
		int pre = 0;
		for(auto t : mdf[i]){
			ans[pre] += pw(N) - val; ans[t.first] -= pw(N) - val;
			t.second > 0 ? cut(t.second) : link(-t.second); pre = t.first;
		}
		ans[pre] += pw(N) - val; reverse(mdf[i].begin() , mdf[i].end()); for(auto t : mdf[i]) t.second > 0 ? link(t.second) : cut(-t.second);
	}
	for(int i = 1 ; i <= M ; ++i) ans[i] += ans[i - 1];
	for(int i = 0 ; i <= M ; ++i) printf("%lld\n" , ans[i]);
	return 0;
}