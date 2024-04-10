#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

#define id(i,j) ((i - 1) * D + j)
const int MAXN = (1e5 + 1) * 50;
vector < int > ch[MAXN];
struct Edge{
	int end , upEd;
}Ed[MAXN];
int head[MAXN] , dfn[MAXN] , low[MAXN] , stk[MAXN] , sum[MAXN] , in[MAXN] , ans[MAXN];
int cntEd , top , N , M , D , ts , cntSCC;
bool vis[MAXN] , ins[MAXN] , open[MAXN] , mrk[100003];

inline void addEd(int a , int b){
	Ed[++cntEd] = (Edge){b , head[a]};
	head[a] = cntEd;
}

void pop(int x){
	++cntSCC;
	vector < int > nd;
	do{
		int t = stk[top];
		nd.push_back(t / D);
		ins[t] = 0; in[t] = cntSCC;
		if(!mrk[t / D] && open[t]){
			mrk[t / D] = 1;
			++sum[cntSCC];
		}
	}while(stk[top--] != x);
	for(auto t : nd) mrk[t] = 0;
}

void tarjan(int x){
	dfn[x] = low[x] = ++ts;
	vis[x] = ins[x] = 1;
	stk[++top] = x;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		if(!vis[Ed[i].end]) tarjan(Ed[i].end);
		else if(!ins[Ed[i].end]) continue;
		low[x] = min(low[x] , low[Ed[i].end]);
	}
	if(dfn[x] == low[x]) pop(x);
}

int dfs(int x){
	if(ans[x] != -1) return ans[x];
	ans[x] = 0;
	for(auto t : ch[x]) ans[x] = max(ans[x] , dfs(t));
	return ans[x] += sum[x];
}

inline char getc(){
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	return c;
}

int main(){
	memset(ans , -1 , sizeof(ans));
	N = read(); M = read(); D = read();
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		for(int j = 0 ; j < D ; ++j)
			addEd(id(a , j) , id(b , (j + 1) % D));
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j < D ; ++j)
			open[id(i , j)] = getc() - '0';
	tarjan(0);
	for(int i = 0 ; i <= id(N , (D - 1)) ; ++i)
		if(in[i])
			for(int j = head[i] ; j ; j = Ed[j].upEd)
				if(in[Ed[j].end] && in[i] != in[Ed[j].end])
					ch[in[i]].push_back(in[Ed[j].end]);
	cout << dfs(in[0]) << endl;
	return 0;
}