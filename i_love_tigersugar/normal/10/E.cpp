#include<bits/stdc++.h>
#define MAX   404
const int INF=(int)2e9+7;
int a[MAX];
int n;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
int greedy(int x) {
	int ret=0;
	int i;
	for (i=1;i<=n;i=i+1) {
		ret=ret+x/a[i];
		x=x%a[i];
	}
	return (ret);
}
void process(void) {	
	int i,j;
	int cur,req,t,r;
	int best=INF;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	for (i=1;i<n;i=i+1) {
		req=0;
		cur=0;
		for (j=i+1;j<=n;j=j+1) {
			t=(a[i]-cur)/a[j];
			r=t*a[j];
			if (greedy(cur+r+a[j])>req+t+1) minimize(best,cur+r+a[j]);
			cur+=r;
			req+=t;
		}
	}
	if (best>=INF) printf("-1");
	else printf("%d",best);
}
int main(void) {
	process();
	return 0;
}