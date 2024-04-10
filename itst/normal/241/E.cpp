#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 1e4 + 7;
struct Edge{
	int end , upEd , w;
}Ed[_ << 1];
int head[_] , s[_] , t[_] , cntEd , N , M;
vector < int > nxt[_]; bool vis[_];

void addEd(int a , int b , int c){
	Ed[++cntEd] = (Edge){b , head[a] , c};
	head[a] = cntEd;
}

int fl[_] , dis[_]; queue < int > q; bool inq[_];
bool SPFA(){
	q.push(1); memset(dis , 0x3f , sizeof(dis)); dis[1] = 0;
	while(!q.empty()){
		int t = q.front(); q.pop(); inq[t] = 0;
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] > dis[t] + Ed[i].w){
				dis[Ed[i].end] = dis[t] + Ed[i].w;
				if((fl[Ed[i].end] = fl[t] + 1) > N) return 0;
				if(!inq[Ed[i].end]){
					inq[Ed[i].end] = 1; q.push(Ed[i].end);
				}
			}
	}
	return 1;
}

bool fnd[_];
bool dfs(int x){
	if(fnd[x]) return vis[x];
	fnd[x] = 1;
	if(x == 1) return vis[1] = 1;
	for(auto t : nxt[x]) if(dfs(s[t])) vis[x] = 1;
	return vis[x];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); M = read();
	for(int i = 1 ; i <= M ; ++i){
		s[i] = read(); t[i] = read();
		nxt[t[i]].push_back(i);
	}
	dfs(N);
	for(int i = N ; i ; --i)
		if(vis[i])
			for(auto t : nxt[i])
				if(vis[s[t]]){
					addEd(s[t] , i , 2);
					addEd(i , s[t] , -1);
				}
	if(!SPFA()){puts("No"); return 0;}
	for(int i = 2 ; i <= N ; ++i)
		if(dis[i] < 0){puts("No"); return 0;}
	puts("Yes");
	for(int i = 1 ; i <= M ; ++i){
		int p = s[i] , q = t[i];
		if(!vis[p] || !vis[q]) puts("2");
		else printf("%d\n" , dis[q] - dis[p]);
	}
	return 0;
}