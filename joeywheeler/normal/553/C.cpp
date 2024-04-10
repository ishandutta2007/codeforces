#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
int n,m,x,y,t,c[100005];
std::vector<int> a[100005],b[100005];
void g(int i, int d) {
	if (c[i] && c[i] != d) printf("0\n"), exit(0);
	else if (!c[i]) {
		c[i] = d;
		for (int x : a[i]) g(x,d);
		for (int x : b[i]) g(x,3-d);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	FO(i,0,m) {
		scanf("%d%d%d", &x, &y, &t);
		(t?a[x]:b[x]).push_back(y);
		(t?a[y]:b[y]).push_back(x);
	}
	int r = 500000004;
	FO(i,1,n+1) if (!c[i]) g(i,1), r = r*2%1000000007;
	printf("%d\n", r);
}