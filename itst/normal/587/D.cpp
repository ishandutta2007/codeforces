#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 7e5 + 7 , __ = 5e6 + 7; struct Edge{int end , upEd;}Ed[__]; int head[_] , cntEd;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}
int in[_] , dfn[_] , low[_] , stk[_] , top , ts , scc; bool ins[_];
void tarjan(int x){
	dfn[x] = low[x] = ++ts; stk[++top] = x; ins[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		if(!dfn[Ed[i].end]) tarjan(Ed[i].end);
		else if(!ins[Ed[i].end]) continue;
		low[x] = min(low[x] , low[Ed[i].end]);
	}
	if(dfn[x] == low[x]){++scc; do{ins[stk[top]] = 0; in[stk[top]] = scc;}while(stk[top--] != x);}
}

struct dat{int c , id;}; int N , M , S[_] , T[_] , C[_] , W[_] , cnode; vector < dat > nxt[_];
void build(vector < dat > nxt , bool f){
	int pre = 0; for(auto t : nxt){addEd(++cnode , f * M + t.id); if(pre){addEd(cnode , pre); addEd(t.id + (f ^ 1) * M , pre);} pre = cnode;}
}
bool check(int mid){
	cnode = 2 * M; cntEd = 0; memset(head , 0 , sizeof(head)); for(int i = 1 ; i <= M ; ++i) if(W[i] > mid) addEd(i , i + M);
	for(int i = 1 ; i <= N ; ++i){
		build(nxt[i] , 1); reverse(nxt[i].begin() , nxt[i].end()); build(nxt[i] , 1); int p = 0;
		while(p < nxt[i].size()){
			vector < dat > pot; int c = nxt[i][p].c; while(p < nxt[i].size() && nxt[i][p].c == c) pot.push_back(nxt[i][p++]);
			build(pot , 0); reverse(pot.begin() , pot.end()); build(pot , 0);
		}
	}
	memset(dfn , 0 , sizeof(dfn)); ts = scc = 0; 
	for(int i = 1 ; i <= 2 * M ; ++i) if(!dfn[i]) tarjan(i);
	for(int i = 1 ; i <= M ; ++i) if(in[i] == in[i + M]) return 0;
	return 1;
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= M ; ++i){S[i] = read(); T[i] = read(); C[i] = read(); W[i] = read();}
	for(int i = 1 ; i <= M ; ++i){nxt[S[i]].push_back((dat){C[i] , i}); nxt[T[i]].push_back((dat){C[i] , i});}
	for(int i = 1 ; i <= N ; ++i) sort(nxt[i].begin() , nxt[i].end() , [&](dat p , dat q){return p.c < q.c;});		
	int L = 0 , R = 1e9 + 1; while(L < R){int mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;}
	if(L == 1e9 + 1) puts("No");
	else{
		puts("Yes"); check(L); vector < int > seq;
		for(int i = 1 ; i <= M ; ++i) if(in[i] < in[i + M]) seq.push_back(i);
		printf("%d %d\n" , L , seq.size()); for(auto t : seq) printf("%d " , t);
	}
	return 0;
}