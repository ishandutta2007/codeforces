#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 2e5 + 7; vector < int > nxt[_]; int N , M , h[_] , dis[_] , val[_]; bool vis[_];
int getdis(int x){
	if(vis[x]) return dis[x];
	for(auto t : nxt[x]) getdis(t);
	static int mex[_]; for(auto t : nxt[x]) mex[getdis(t)] = 1;
	while(mex[dis[x]]) ++dis[x];
	for(auto t : nxt[x]) mex[getdis(t)] = 0;
	vis[x] = 1; return dis[x];
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= N ; ++i) h[i] = read();
	for(int i = 1 ; i <= M ; ++i){int x = read() , y = read(); nxt[x].push_back(y);}
	for(int i = 1 ; i <= N ; ++i) val[getdis(i)] ^= h[i];
	for(int i = N ; i >= 0 ; --i)
		if(val[i]){
			puts("WIN");
			for(int j = 1 ; j <= N ; ++j)
				if(dis[j] == i && (h[j] ^ val[i]) < h[j]){
					h[j] = h[j] ^ val[i];
					for(auto t : nxt[j]){h[t] = val[dis[t]] ^ h[t]; val[dis[t]] = 0;}
					break;
				}
			for(int j = 1 ; j <= N ; ++j) printf("%d " , h[j]);
			return 0;
		}
	puts("LOSE");
	return 0;
}