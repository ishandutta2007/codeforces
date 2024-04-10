#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 2e5 + 7;
struct Edge{int end , upEd;};
int N , M;
namespace tree{
	Edge Ed[_ << 1]; int head[_] , cntEd , cnt; long long val[_];
	void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

	int dep[_] , up[_][19]; long long sum[_][19];
	void dfs(int x , int p){
		up[x][0] = p; sum[x][0] = val[x]; dep[x] = dep[p] + 1;
		for(int i = 1 ; up[x][i - 1] ; ++i){
			up[x][i] = up[up[x][i - 1]][i - 1];
			sum[x][i] = sum[x][i - 1] + sum[up[x][i - 1]][i - 1];
		}
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].end != p) dfs(Ed[i].end , x);
	}

	pair < int , long long > LCA(int x , int y){
		if(dep[x] < dep[y]) swap(x , y);
		long long s = 0;
		for(int i = 18 ; i >= 0 ; --i)
			if(dep[x] - (1 << i) >= dep[y]){s += sum[x][i]; x = up[x][i];}
		if(x == y) return make_pair(x , s);
		for(int i = 18 ; i >= 0 ; --i)
			if(up[x][i] != up[y][i]){s = s + sum[x][i] + sum[y][i]; x = up[x][i]; y = up[y][i];}
		return make_pair(up[x][0] , s + val[x] + val[y] + (up[x][0] > N ? val[up[x][0]] : 0));
	}
		
	void work(){
		dfs(0 , 0);
		for(int Q = read() ; Q ; --Q){
			int x = read() , y = read(); pair < int , long long > t = LCA(x , y);
			if(t.first && ((t.second & 1) || t.second > cnt)) puts("Yes");
			else puts("No");
		}
	}
}

namespace graph{
	Edge Ed[_ << 1]; int head[_] , cntEd;
	void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}
	
	int col[_] , dfn[_] , low[_] , stk[_] , top , ts;
	bool color(int x , int c){
		bool flg = 1; col[x] = c;
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(col[Ed[i].end] == col[x]) flg = 0;
			else if(col[Ed[i].end] == -1) flg &= color(Ed[i].end , c ^ 1);
		return flg;
	}
	
	void pop(int x , int p){
		int cur = top , rt = ++tree::cnt; col[p] = -1; tree::addEd(p , rt);
		do{col[stk[cur]] = -1; tree::addEd(rt , stk[cur]);}while(stk[cur--] != x);
		tree::val[rt] = !color(x , 0) * 1e6; if(!p) col[p] = 0;
		for(int i = cur + 1 ; i <= top ; ++i){
			tree::val[stk[i]] = col[p] ^ col[stk[i]]; col[stk[i]] = 1e8;
		}
		top = cur; col[p] = 1e8;
	}

	void tarjan(int x , int p){
		low[x] = dfn[x] = ++ts; stk[++top] = x; int cnt = 0;
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(dfn[Ed[i].end]) low[x] = min(low[x] , dfn[Ed[i].end]);
			else{
				tarjan(Ed[i].end , x); low[x] = min(low[x] , low[Ed[i].end]);
				if(p && low[Ed[i].end] >= dfn[x] || (!p && ++cnt >= 2)) pop(Ed[i].end , x);
			}
	}

	void init(){
		memset(col , 0x3f , sizeof(col));
		for(int i = 1 ; i <= M ; ++i){int x = read() , y = read(); addEd(x , y); addEd(y , x);}
		tree::cnt = N; for(int i = 1 ; i <= N ; ++i) if(!dfn[i]){tarjan(i , 0); pop(i , 0);}
	}
}

int main(){N = read(); M = read(); graph::init(); tree::work(); return 0;}