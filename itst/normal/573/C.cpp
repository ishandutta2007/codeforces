#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 100010;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , in[MAXN] , N , cntEd;
queue < int > q;
bool vis[MAXN] , have[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
	++in[b];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	for(int i = 1 ; i <= N ; ++i)
		if(in[i] == 1){
			vis[i] = 1;
			q.push(i);
		}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(!vis[Ed[i].end] && in[Ed[i].end] <= 2){
				vis[Ed[i].end] = 1;
				q.push(Ed[i].end);
			}
	}
	for(int i = 1 ; i <= N ; ++i)
		if(!vis[i]){
			int cnt = 0;
			for(int j = head[i] ; j ; j = Ed[j].upEd)
				cnt += vis[Ed[j].end];
			if(in[i] - min(2 , cnt) > 1)
				have[i] = 1;
		}
	for(int i = 1 ; i <= N ; ++i)
		if(have[i]){
			int cnt = 0;
			for(int j = head[i] ; j ; j = Ed[j].upEd)
				cnt += have[Ed[j].end];
			if(cnt > 2){
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	return 0;
}