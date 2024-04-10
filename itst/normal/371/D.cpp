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

const int MAXN = 200010;
int fa[MAXN] , maxN[MAXN] , now[MAXN] , N , M;

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("371D.in" , "r" , stdin);
	//freopen("371D.out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		maxN[i] = read();
		fa[i] = i;
	}
	fa[N + 1] = N + 1;
	for(int M = read() ; M ; --M)
		if(read() == 1){
			int a = read() , b = read();
			int t = find(a);
			while(b && t != N + 1)
				if(maxN[t] - now[t] <= b){
					b -= maxN[t] - now[t];
					now[t] = maxN[t];
					fa[t] = t + 1;
					t = find(t);
				}
				else{
					now[t] += b;
					b = 0;
				}
		}
		else
			printf("%d\n" , now[read()]);
	return 0;
}