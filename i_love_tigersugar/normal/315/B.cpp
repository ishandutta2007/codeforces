#include<cstdio>
#define MAX   100100
int a[MAX];
int s,n,m;
void init(void) {
	int i;
	scanf("%d",&n);
	scanf("%d",&m);
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	s=0;	
}
void process(void) {
	int i,t,u,v;
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&u);
		if (t==1) {
			scanf("%d",&v);
			a[u]=v-s;
		}
		if (t==2) s=s+u;
		if (t==3) printf("%d\n",a[u]+s);
	}
}
int main(void) {	
	init();
	process();
	return 0;
}