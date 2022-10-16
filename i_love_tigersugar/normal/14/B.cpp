#include<bits/stdc++.h>
#define MAX   2020
const int INF=(int)1e9;
int pnt[MAX];
int n,fst;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
int iabs(const int &x) {
	if (x<0) return (-x); else return (x);
}
void init(void) {
	memset(pnt,0,sizeof pnt);
	scanf("%d",&n);
	scanf("%d",&fst);
	int x,y,i,j;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&x);
		scanf("%d",&y);
		for (j=min(x,y);j<=max(x,y);j=j+1) pnt[j]++;
	}
	int res=INF;
	for (i=0;i<=1111;i=i+1)
		if (pnt[i]==n) res=min(res,iabs(fst-i));
	if (res>=INF) printf("-1");
	else printf("%d",res);
}
int main(void) {
	init();
	return 0;
}