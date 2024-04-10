#include <bits/stdc++.h>
using namespace std;

int n, m, a[101][101], r1, c1, r[101], c[101], mn = 1e9, mi;

void T_T(){ puts("-1"); exit(0); }

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) scanf("%d", a[i] + j);
	}
	for(int i = 2; i <= n; i++){
		r[i] = a[i][1] - a[i - 1][1];
		for(int j = 2; j <= m; j++){
			if(r[i] != a[i][j] - a[i - 1][j]) T_T();
		}
		r[i] += r[i - 1];
	}
	for(int i = 2; i <= m; i++){
		c[i] = a[1][i] - a[1][i - 1];
		for(int j = 2; j <= n; j++){
			if(c[i] != a[j][i] - a[j][i - 1]) T_T();
		}
		c[i] += c[i - 1];
	}
	for(int i = 0, cs, fl; i <= a[1][1]; i++){
		r1 = i; c1 = a[1][1] - i;
		cs = a[1][1]; fl = 1;
		for(int j = 2; j <= n; j++){
			if(r1 + r[j] < 0) fl = 0;
			cs += r1 + r[j];
		}
		for(int j = 2; j <= m; j++){
			if(c1 + c[j] < 0) fl = 0;
			cs += c1 + c[j];
		}
		if(fl && cs < mn){
			mn = cs;
			mi = i;
		}
	}
	if(mn > 9e8) T_T();
	printf("%d\n", mn);
	for(int i = 1; i <= n; i++) for(int j = 0; j < mi + r[i]; j++) printf("row %d\n", i);
	for(int i = 1; i <= m; i++) for(int j = 0; j < a[1][1] - mi + c[i]; j++) printf("col %d\n", i);
}