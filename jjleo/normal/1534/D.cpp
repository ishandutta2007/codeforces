#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int d[maxn], fa[maxn];
int a[maxn], b[maxn];

inline bool cmp(int x, int y){
	return d[x] < d[y];
}

int main(){
	scanf("%d", &n);
	puts("? 1"), fflush(stdout);
	for(int i = 1;i <= n;i++){
		scanf("%d", &d[i]);
		if(d[i] == 1) fa[i] = 1;
		a[i] = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int I = 1;I <= n;I++){
		int i = a[I];
		if(i == 1 || fa[i]) continue;
		printf("? %d\n", i), fflush(stdout);
		for(int j = 1;j <= n;j++) scanf("%d", &b[j]);
		for(int j = 1;j <= n;j++) if(b[j] == 1){
			if(d[j] > d[i]) fa[j] = i;
			else fa[i] = j;
		}
		for(int j = 1;j <= n;j++) if(b[j] == 2 && d[i] == d[j]) fa[j] = fa[i];
	}
	puts("!"), fflush(stdout);
	for(int i = 2;i <= n;i++) printf("%d %d\n", i, fa[i]), fflush(stdout);
}