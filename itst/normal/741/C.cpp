#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 2e5 + 7;
int col[_] , plc[_] , N;
vector < int > to[_];

void dfs(int x){for(auto t : to[x]) if(col[t] == -1){col[t] = col[x] ^ 1; dfs(t);}}

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		plc[i * 2 - 1] = read(); plc[i * 2] = read();
		to[plc[i * 2 - 1]].push_back(plc[i * 2]);
		to[plc[i * 2]].push_back(plc[i * 2 - 1]);
	}
	for(int i = 1 ; i <= 2 * N ; i += 2){
		to[i].push_back(i + 1); to[i + 1].push_back(i);
	}
	memset(col , -1 , sizeof(col));
	for(int i = 1 ; i <= 2 * N ; ++i) if(col[i] == -1){col[i] = 1; dfs(i);}
	for(int i = 1 ; i <= N ; ++i) printf("%d %d\n" , col[plc[i * 2 - 1]] + 1 , col[plc[i * 2]] + 1);
	return 0;
}