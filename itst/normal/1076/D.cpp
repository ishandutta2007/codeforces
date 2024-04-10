#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 300010;
struct Edge{
	int end , upEd , w;
}Ed[MAXN << 1];
int head[MAXN] , N , M , k , cntEd = 1;
bool vis[MAXN];
long long minDis[MAXN];
priority_queue < pair < long long , int > > q;

inline void addEd(int a , int b , int c){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	Ed[cntEd].w = c;
	head[a] = cntEd;
}

void Dijk(){
	memset(minDis , 0x7f , sizeof(minDis));
	minDis[1] = 0;
	q.push(make_pair(0 , 1));
	while(!q.empty()){
		pair < long long , int > t = q.top();
		q.pop();
		if(-t.first > minDis[t.second])
			continue;
		for(int i = head[t.second] ; i ; i = Ed[i].upEd)
			if(minDis[Ed[i].end] > minDis[t.second] + Ed[i].w){
				minDis[Ed[i].end] = minDis[t.second] + Ed[i].w;
				q.push(make_pair(-minDis[Ed[i].end] , Ed[i].end));
			}
	}
}

void dfs(int now){
	vis[now] = 1;
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end] && minDis[Ed[i].end] == minDis[now] + Ed[i].w){
			printf("%d " , (i >> 1));
			if(!--k)
				exit(0);
			dfs(Ed[i].end);
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("1076D.in" , "r" , stdin);
	//freopen("1076D.out" , "w" , stdout);
#endif
	N = read();
	M = read();
	k = read();
	printf("%d\n" , min(N - 1 , k));
	if(!k)
		return 0;
	for(int i = 1 ; i <= M ; i++){
		int a = read() , b = read() , c = read();
		addEd(a , b , c);
		addEd(b , a , c);
	}
	Dijk();
	dfs(1);
	return 0;
}