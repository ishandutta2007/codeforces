 #include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
int cur = 82;
int st[10],en[10];
bool g[1001][1001];
int main() {
	int n,i,j,k,l;
	scanf("%d", &n);
	for (i = 0; i < 10; i++) {
		st[i] = ++cur;
		if (i != 0)for (j = 0; j < 8; j++)g[st[i]][++cur] = 1;
		for (j = 1; j < i; j++) {
			for (k = 0; k < 8; k++)for (l = 1; l <= 8; l++)g[cur - k][cur + l] = 1;
			cur += 8;
		}
		if (i != 0) {
			for (k = 0; k < 8; k++)g[cur - k][cur + 1] = 1;
			cur++;
		}
		else {
			g[cur][++cur] = 1;
		}
		for (j = 0; j < 9 - i; j++)g[cur][++cur] = 1;
		en[i] = cur;
		g[2][en[i]] = 1;
	}
	int ans;
	printf("%d\n", ans=cur);
	cur = 3;
	for (i = 0; i <= 9; i++) {
		for (j = 0; j < ((n >> (3 * i)) & 7); j++)g[1][cur]=1,g[cur][st[i]]=1, cur++;
	}
	for (i = 1; i <= ans; i++) {
		for (j = 1; j <= ans; j++)printf("%c",g[min(i,j)][max(i,j)]?'Y':'N');
		printf("\n");
	}
}