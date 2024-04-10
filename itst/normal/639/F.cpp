#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 6e5 + 7; int ch[_][2] , fa[_] , cnt[_] , add[_] , mn[_]; bool swp[_];

bool nroot(int x){return ch[fa[x]][0] == x || ch[fa[x]][1] == x;}
bool son(int x){return ch[fa[x]][1] == x;}
void upd(int x){mn[x] = !x ? 1e9 : min(cnt[x] , min(mn[ch[x][0]] , mn[ch[x][1]]));}
void rot(int x){
	bool f = son(x); int y = fa[x] , z = fa[y] , w = ch[x][f ^ 1];
	fa[x] = z; if(nroot(y)) ch[z][son(y)] = x;
	fa[y] = x; ch[x][f ^ 1] = y; ch[y][f] = w; if(w) fa[w] = y;
	upd(y);
}

void swap(int x){swp[x] ^= 1; swap(ch[x][0] , ch[x][1]);} void inc(int x , int v){add[x] += v; mn[x] += v; cnt[x] += v;}
void down(int x){if(swp[x]){swap(ch[x][0]); swap(ch[x][1]); swp[x] = 0;} if(add[x]){inc(ch[x][0] , add[x]); inc(ch[x][1] , add[x]); add[x] = 0;}}
void dall(int x){if(nroot(x)){dall(fa[x]);} down(x);}
void splay(int x){dall(x); while(nroot(x)){if(nroot(fa[x])){rot(son(fa[x]) == son(x) ? fa[x] : x);} rot(x);} upd(x);}

void access(int x){for(int y = 0 ; x ; y = x , x = fa[x]){splay(x); ch[x][1] = y; upd(x);}}
int fdrt(int x){access(x); splay(x); while(ch[x][0]){down(x = ch[x][0]);} splay(x); return x;}
void mkrt(int x){access(x); splay(x); swap(x);}
void link(int x , int y){mkrt(x); fa[x] = y;}
void split(int x , int y){mkrt(x); access(y); splay(y);}
void cut(int x , int y){split(x , y); down(y); ch[y][0] = fa[ch[y][0]] = 0; upd(y);}
void mdf(int x , int y , int v){split(x , y); inc(y , v);}

int main(){
	int N = read() , M = read() , Q = read() , cnode = N; mn[0] = 1e9; for(int i = 1 ; i <= N ; ++i) cnt[i] = mn[i] = 1;
	for(int i = 1 ; i <= M ; ++i){int x = read() , y = read(); if(fdrt(x) != fdrt(y)){++cnode; link(x , cnode); link(y , cnode);} else mdf(x , y , 1);}
	int R = 0;
	for(int i = 1 ; i <= Q ; ++i){
		vector < int > node; vector < pair < int , int > > edge; vector < bool > state;
		int n = read() , m = read(); for(int i = 1 ; i <= n ; ++i) node.push_back((read() + R - 1) % N + 1);
		for(int i = 1 ; i <= m ; ++i) edge.push_back(make_pair((read() + R - 1) % N + 1 , (read() + R - 1) % N + 1));
		
		for(int i = 0 ; i < m ; ++i){
			int x = edge[i].first , y = edge[i].second; bool f = fdrt(x) != fdrt(y); state.push_back(f);
			if(f){++cnode; link(x , cnode); link(y , cnode);} else mdf(x , y , 1);
		}
		
		bool ans = 1;
		for(int i = 1 ; ans && i < node.size() ; ++i)
			if(fdrt(node[i]) != fdrt(node[i - 1])) ans = 0; else{split(node[i - 1] , node[i]); ans &= !!mn[node[i]];}
		R = (R + ans * i) % N; puts(ans ? "YES" : "NO");
		while(state.size()){
			int x = edge.back().first , y = edge.back().second; 
			if(!state.back()) mdf(x , y , -1); else{cut(x , cnode); cut(y , cnode); --cnode;}
			edge.pop_back(); state.pop_back();
		}
	}
	return 0;
}