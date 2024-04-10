#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 2e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int N , M , cntEd , head[_] , P[_];
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int dis[_] , cnt[_];
void bfs(int x){
	queue < int > q; q.push(P[P[0]]); memset(dis , 0x3f , sizeof(dis)); dis[x] = 0; cnt[P[P[0]]] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] == dis[0]){dis[Ed[i].end] = dis[t] + 1; q.push(Ed[i].end); cnt[Ed[i].end] = 1;}
			else if(dis[Ed[i].end] == dis[t] + 1) ++cnt[Ed[i].end];
	}
}

int main(){
	N = read(); M = read();
	for(int i = 1 ; i <= M ; ++i){int a = read() , b = read(); addEd(b , a);}
	P[0] = read(); for(int i = 1 ; i <= P[0] ; ++i) P[i] = read();
	bfs(P[P[0]]); int pos = 1 , val = 0;
	while(pos < P[0]){
		int sum = 0 , p = pos; while(p < P[0] && (++sum) + dis[P[p + 1]] == dis[P[pos]]) ++p;
		++val; pos = p + 1;
	}
	cout << --val << ' '; val = 0;
	for(int i = 1 ; i < P[0] ; ++i) val += dis[P[i]] != dis[P[i + 1]] + 1 || cnt[P[i]] > 1;
	cout << val;
	return 0;
}