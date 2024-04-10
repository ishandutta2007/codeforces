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

const int MAXN = 4e5 + 10;
int N , D , K , cnt , fa[MAXN] , dep[MAXN];

void dfs(int x){
	if(N == cnt){
		puts("YES");
		for(int i = 2 ; i <= cnt ; ++i)
			printf("%d %d\n" , fa[i] , i);
		exit(0);
	}
	if(dep[x] == 1){
		fa[++cnt] = x;
		dep[cnt] = dep[x] + 1;
		dfs(cnt);
	}
	else
		if(dep[x] != D)
			for(int i = 1 ; i < K ; ++i){
				fa[++cnt] = x;
				if(i == 1)
					dep[cnt] = dep[x] + 1;
				else
					dep[cnt] = max(dep[x] + 1 , D - dep[x] + 2);
				dfs(cnt);
			}
}

int main(){
	dep[1] = 1;
	N = read();
	D = read() + 1;
	K = read();
	if(N < D){
		puts("NO");
		return 0;
	}
	dfs(cnt = 1);
	puts("NO");
	return 0;
}