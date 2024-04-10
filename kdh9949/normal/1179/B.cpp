#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	int l = 1, u = n;
	while(l < u){
		for(int i = 1, j = m; i <= m; i++, j--)
			printf("%d %d\n%d %d\n", l, i, u, j);
		l++; u--;
	}
	if(l == u){
		for(int i = 1, j = m; i < j; i++, j--)
			printf("%d %d\n%d %d\n", l, i, l, j);
		if(m & 1) printf("%d %d\n", l, m / 2 + 1);
	}
	return 0;
}