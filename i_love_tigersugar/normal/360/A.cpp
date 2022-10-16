#include<bits/stdc++.h>
#define MAX   5050
const int INF=(int)1e9+7;
int a[MAX];
int d[MAX];
struct query {
	int t,l,r,v;
	query(){}
	void input(void) {
		scanf("%d",&t);
		scanf("%d",&l);
		scanf("%d",&r);
		scanf("%d",&v);
	}
};
query q[MAX];
int n,m;
void readinp(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	int i;
	memset(a,0x3f,sizeof a);	
	for (i=1;i<=m;i=i+1) q[i].input();
}
void update(const query &q) {
	int i;
	for (i=q.l;i<=q.r;i=i+1) d[i]+=q.v;
}
void change(const query &q) {
	int i;
	for (i=q.l;i<=q.r;i=i+1)
		if (a[i]>q.v-d[i]) a[i]=q.v-d[i];
}
bool ok(const query &q) {
	int i;
	int ret=-INF;
	for (i=q.l;i<=q.r;i=i+1)
		if (ret<a[i]+d[i]) ret=a[i]+d[i];
	return (ret==q.v);
}
void process(void) {
	int i;
	for (i=1;i<=m;i=i+1) {
		if (q[i].t==1) update(q[i]);
		else change(q[i]);
	}
	memset(d,0,sizeof d);
	for (i=1;i<=m;i=i+1) {
		if (q[i].t==1) update(q[i]);
		else {
			if (!ok(q[i])) {
				printf("NO");
				return;
			}
		}
	}
	printf("YES\n");
	for (i=1;i<=n;i=i+1)
		if (a[i]>INF) a[i]=0;
	for (i=1;i<n;i=i+1) printf("%d ",a[i]);
	printf("%d",a[n]);
}
int main(void) {	
	readinp();
	process();
	return 0;
}