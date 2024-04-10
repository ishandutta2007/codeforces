#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 2e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , cntEd , N , Q , K , M;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int dfn[_] , up[_][20] , ts , dep[_];
void dfs(int x , int p){
	dfn[x] = ++ts; up[x][0] = p; dep[x] = dep[p] + 1;
	for(int i = 1 ; up[x][i - 1] ; ++i) up[x][i] = up[up[x][i - 1]][i - 1];
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) dfs(Ed[i].end , x);
}

int LCA(int p , int q){
	if(dep[p] < dep[q]) swap(p , q);
	for(int i = 19 ; i >= 0 ; --i)
		if(dep[p] - (1 << i) >= dep[q]) p = up[p][i];
	if(p == q) return p;
	for(int i = 19 ; i >= 0 ; --i)
		if(up[p][i] != up[q][i]){p = up[p][i]; q = up[q][i];}
	return up[p][0];
}

vector < int > node , nxt[_] , in;
int st[_] , id[_] , speed[_];
int build(){
	sort(node.begin() , node.end() , [&](int p , int q){return dfn[p] < dfn[q];});
	node.resize(unique(node.begin() , node.end()) - node.begin());
	static int stk[_]; int top = 0;
	for(auto t : node){
		if(top){
			int p = LCA(stk[top] , t);
			while(dep[stk[top - 1]] > dep[p]){nxt[stk[top - 1]].push_back(stk[top]); --top;}
			if(stk[top] != p){
				nxt[p].push_back(stk[top]);
				if(stk[--top] != p){stk[++top] = p; in.push_back(p);}
			}
		}
		stk[++top] = t; in.push_back(t);
	}
	for(int i = 2 ; i <= top ; ++i) nxt[stk[i - 1]].push_back(stk[i]);
	return stk[1];
}

int dist(int x , int y){return dep[x] + dep[y] - 2 * dep[LCA(x , y)];}
int spr(int id , int x){return (dist(st[id] , x) + speed[id] - 1) / speed[id];}
void dfs1(int x){
	for(auto t : nxt[x]){
		dfs1(t); int idp = id[t] , idq = id[x]; if(idp > idq) swap(idp , idq);
		id[x] = !idp ? idq : (spr(idp , x) <= spr(idq , x) ? idp : idq);
	}
}

void dfs2(int x){
	for(auto t : nxt[x]){
		int idp = id[t] , idq = id[x]; if(idp > idq) swap(idp , idq);
		id[t] = !idp ? idq : (spr(idp , t) <= spr(idq , t) ? idp : idq); dfs2(t);
	}
}

void clear(){for(auto t : in){id[t] = 0; nxt[t].clear();} in.clear();}

int main(){
	N = read();
	for(int i = 1 ; i < N ; ++i){int x = read() , y = read(); addEd(x , y); addEd(y , x);}
	dfs(1 , 0);
	for(Q = read() ; Q ; --Q){
		int K = read() , M = read(); node.clear(); vector < int > imp;
		for(int i = 1 ; i <= K ; ++i){id[st[i] = read()] = i; speed[i] = read(); node.push_back(st[i]);}
		for(int i = 1 ; i <= M ; ++i){int t = read(); imp.push_back(t); node.push_back(t);}
		int rt = build(); dfs1(rt); dfs2(rt);
		for(int i = 1 ; i <= M ; ++i) printf("%d%c" , id[imp[i - 1]] , " \n"[i == M]);
		clear();
	}
	return 0;
}