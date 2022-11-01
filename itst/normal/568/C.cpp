#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}

char getc(){
	char c = getchar();
	while(!isalpha(c)) c = getchar();
	return c;
}

const int _ = 1003 , __ = 1e6 + 7;
struct Edge{int end , upEd;}Ed[__];
int head[_] , cntEd , sigma , N , M; char alg[_] , str[_];

void addEd(int p , int q){
	Ed[++cntEd] = (Edge){q , head[p]};
	head[p] = cntEd;
}

int dfn[_] , low[_] , in[_] , stk[_] , top , scc , ts; bool ins[_];
void tarjan(int x){
	dfn[x] = low[x] = ++ts; stk[++top] = x; ins[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		if(!dfn[Ed[i].end]) tarjan(Ed[i].end);
		else if(!ins[Ed[i].end]) continue;
		low[x] = min(low[x] , low[Ed[i].end]);
	}
	if(dfn[x] == low[x]){
		++scc;
		do{
			ins[stk[top]] = 0;
			in[stk[top]] = scc;
		}while(stk[top--] != x);
	}
}

bool vis[_] , tmp[_];

bool dfs(int x){
	if(tmp[x]) return 1;
	tmp[x] = 1; if(tmp[x > N ? x - N : x + N]) return 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!dfs(Ed[i].end)) return 0;
	return 1;
}

char ans[_];
bool searchans(int p , bool along){
	if(p > N){printf("%s" , ans + 1); return 1;}
	bool flg1 , flg2 , cur[_] , tp[2][_];
	memcpy(cur , vis , sizeof(cur));
	if(vis[p] || vis[p + N]){
		flg1 = vis[p]; flg2 = vis[p + N];
		memcpy(tp[0] , vis , sizeof(vis));
		memcpy(tp[1] , vis , sizeof(vis));
	}
	else{
		memcpy(tmp , vis , sizeof(tmp)); 
		flg1 = dfs(p); memcpy(tp[0] , tmp , sizeof(tmp));
		memcpy(tmp , vis , sizeof(tmp)); 
		flg2 = dfs(p + N); memcpy(tp[1] , tmp , sizeof(tmp));
	}
	for(int i = 0 ; i < sigma ; ++i)
		if(!along || i >= str[p] - 'a')
			if(alg[i] == 'C' ? flg1 : flg2){
				ans[p] = i + 'a';
				memcpy(vis , tp[alg[i] == 'V'] , sizeof(vis));
				bool flg = along & (i == str[p] - 'a');
				if(searchans(p + 1 , flg)) return 1;
				memcpy(vis , cur , sizeof(vis));
				if(!flg) return 0;
			}
	return 0;
}

int main(){
	scanf("%s" , alg); sigma = strlen(alg);
	N = read(); M = read();
	for(int i = 1 ; i <= M ; ++i){
		int x , y; bool cx , cy;
		x = read(); cx = getc() == 'V'; y = read(); cy = getc() == 'V';
		addEd(x + cx * N , y + cy * N);
		addEd(y + (cy ^ 1) * N , x + (cx ^ 1) * N);
	}
	scanf("%s" , str + 1);
	for(int i = 1 ; i <= 2 * N ; ++i) if(!dfn[i]) tarjan(i);
	if(!searchans(1 , 1)) puts("-1");
	return 0;
}