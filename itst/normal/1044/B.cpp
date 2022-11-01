#include<bits/stdc++.h>
//This code is written by Itst
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

struct Edge{
	int end , upEd;
}Ed[2010];
bool vis1[1010] , vis2[1010];
int head[1010] , cntEd , dep[1010] , minDep , minInd;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs(int x , int p){
	dep[x] = dep[p] + 1;
	if(vis1[x]){
		if(minDep > dep[x])
			minDep = dep[minInd = x];
		return;
	}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			dfs(Ed[i].end , x);
}

int main(){
	for(int T = read() ; T ; --T){
		int N = read();
		memset(vis1 , 0 , sizeof(vis1));
		memset(vis2 , 0 , sizeof(vis2));
		memset(head , 0 , sizeof(head));
		cntEd = 0;
		for(int i = 1 ; i < N ; ++i){
			int a = read() , b = read();
			addEd(a , b);
			addEd(b , a);
		}
		minDep = N + 1;
		for(int K1 = read() ; K1 ; --K1)
			vis1[read()] = 1;
		int st;
		for(int K2 = read() ; K2 ; --K2)
			vis2[st = read()] = 1;
		cout << "B " << st << endl;
		int K = read();
		dfs(K , 0);
		cout << "A " << minInd << endl;
		cout << "C " << (vis2[read()] ? minInd : -1) << endl;
	}
	return 0;
}