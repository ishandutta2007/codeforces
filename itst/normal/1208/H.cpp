#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define pii pair < int , int >
const int _ = 4e5 + 7; int N , K , Q , sz[_] , fa[_] , ans[_] , col[_]; vector < int > nxt[_];
void dfs(int x , int p){sz[x] = 1; fa[x] = p; for(auto t : nxt[x]) if(t != p){dfs(t , x); sz[x] += sz[t];}}
int op[_][3];

int sum[_]; bool vislim[_]; vector < pii > qry[_];
void calc_change(){
	priority_queue < pair < int , int > > q; for(int i = 1 ; i <= N ; ++i) if(col[i] == -1) col[i] = 1;
	for(int i = 1 ; i <= N ; ++i) for(auto t : nxt[i]) if(t != fa[i]) sum[i] += 2 * col[t] - 1;
	for(int i = 1 ; i <= N ; ++i) if(nxt[i].size() - !!fa[i]) q.push(make_pair(-sum[i] - 1 , i));
	for(int i = -N ; i <= N ; ++i){
		while(!q.empty() && -q.top().first <= i){
			int t = q.top().second; q.pop(); if(vislim[t]) continue;
			col[t] = 0; vislim[t] = 1; if(!vislim[fa[t]] && fa[t]) q.push(make_pair(-(sum[fa[t]] -= 2) - 1 , fa[t]));
		}
		for(auto t : qry[i + N]) ans[t.second] = 2 * col[t.first] - 1;
	}
}

namespace bf{
	int calc(int x){
		if(col[x] != -1) return col[x];
		int sum = 0;
		for(int i = 0 ; i < nxt[x].size() && !(sum + (int)nxt[x].size() - i < K || sum - (int)nxt[x].size() + i >= K) ; ++i)
			if(nxt[x][i] != fa[x]) sum += 2 * calc(nxt[x][i]) - 1;
		return sum >= K;
	}
	void work(){
		for(int i = 1 ; i <= N ; ++i) sort(nxt[i].begin() , nxt[i].end() , [&](int p , int q){return sz[p] < sz[q];});
		for(int i = 1 ; i <= Q ; ++i){
			int tp = op[i][0] , x = op[i][1];
			switch(tp){case 1: cout << calc(x) << '\n'; break; case 2: col[x] = op[i][2]; break; case 3: K = x; break;}
		}
	}
}

int main(){
	N = read(); K = read(); for(int i = 1 ; i < N ; ++i){int u = read() , v = read(); nxt[u].push_back(v); nxt[v].push_back(u);}
	for(int i = 1 ; i <= N ; ++i){col[i] = read();} dfs(1 , 0);
	bool flg = 1; Q = read(); for(int i = 1 ; i <= Q ; ++i){op[i][0] = read(); op[i][1] = read(); if(op[i][0] == 2){op[i][2] = read(); flg = 0;}}
	if(flg){
		for(int i = 1 ; i <= Q ; ++i){int tp = op[i][0] , x = op[i][1]; if(tp == 3) K = x; else qry[K + N].push_back(pii(x , i));}
		calc_change(); for(int i = 1 ; i <= Q ; ++i) if(ans[i]) printf("%d\n" , (ans[i] + 1) / 2);
	}else bf::work();
	return 0;
}