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

const int MAXN = 2e5 + 10;
int fa[MAXN << 1] , N , M , Q;
bool vis[MAXN << 1];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	M = read();
	Q = read();
	for(int i = 1 ; i <= N + M ; ++i)
		fa[i] = i;
	while(Q--){
		int a = read() , b = read();
		fa[find(a)] = find(b + N);
	}
	int cnt = 0;
	for(int i = 1 ; i <= N + M ; ++i)
		if(!vis[find(i)]){
			++cnt;
			vis[find(i)] = 1;
		}
	cout << cnt - 1;
	return 0;
}