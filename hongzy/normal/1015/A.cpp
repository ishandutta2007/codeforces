#include <iostream>
#include <cstdio>

bool flag[110];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, l, r; i<=n; i++) {
		scanf("%d%d", &l, &r);
		for(int j=l; j<=r; j++)
			flag[j] = true;
	}
	int p = 0, cnt = 0;
	for(int i=1; i<=m; i++) 
		if(!flag[i]) ++ cnt;
	printf("%d\n", cnt);
	for(int i=1; i<=m; i++)
		if(!flag[i]) ++ p, printf("%d%c", i, " \n"[p == cnt]);
	return 0;
}