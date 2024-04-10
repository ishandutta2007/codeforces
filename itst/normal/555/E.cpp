#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 2e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , dfn[_] , low[_] , stk[_] , in[_] , top , N , M , Q , cntEd = 1 , ts , cnt;

void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

void pop(int x){++cnt; do{in[stk[top]] = cnt;}while(stk[top--] != x);}

void tarjan(int x , int pid){
	dfn[x] = low[x] = ++ts; stk[++top] = x;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(i != pid){
			if(!dfn[Ed[i].end]) tarjan(Ed[i].end , i ^ 1);
			low[x] = min(low[x] , low[Ed[i].end]);
			if(low[Ed[i].end] > dfn[x]) pop(Ed[i].end);
		}
}

vector < int > nxt[_]; int dep[_] , up[_][20] , sum1[_] , sum2[_];

void dfs(int x , int p){
	dep[x] = dep[p] + 1; up[x][0] = p;
	for(int i = 1 ; up[x][i - 1] ; ++i) up[x][i] = up[up[x][i - 1]][i - 1];
	for(auto t : nxt[x]) if(t != p) dfs(t , x);
}

int LCA(int p , int q){
	if(dep[p] < dep[q]) swap(p , q);
	for(int i = 18 ; i >= 0 ; --i) if(dep[p] - (1 << i) >= dep[q]) p = up[p][i];
	if(p == q) return p;
	for(int i = 18 ; i >= 0 ; --i) if(up[p][i] != up[q][i]){p = up[p][i]; q = up[q][i];}
	return up[p][0];
}

void dfs1(int x , int p){
	for(auto t : nxt[x]) if(t != p){dfs1(t , x); sum1[x] += sum1[t]; sum2[x] += sum2[t];}
	if(sum1[x] && sum2[x]){puts("No"); exit(0);}
}

int main(){
	N = read(); M = read(); Q = read();
	for(int i = 1 ; i <= M ; ++i){int p = read() , q = read(); addEd(p , q); addEd(q , p);}
	for(int i = 1 ; i <= N ; ++i) if(!dfn[i]){tarjan(i , 0); pop(i);}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = head[i] ; j ; j = Ed[j].upEd)
			if(in[Ed[j].end] != in[i]) nxt[in[i]].push_back(in[Ed[j].end]);
	for(int i = 1 ; i <= N ; ++i) if(!dep[i]) dfs(i , 0);
	for(int i = 1 ; i <= Q ; ++i){
		int s = in[read()] , t = in[read()] , p = LCA(s , t);
		if(!p){puts("No"); return 0;}
		++sum1[s]; --sum1[p]; ++sum2[t]; --sum2[p];
	}
	for(int i = 1 ; i <= N ; ++i) if(dep[i] == 1) dfs1(i , 0);
	puts("Yes");
	return 0;
}