#include<bits/stdc++.h>
#define MAX   111
int l[MAX];
int r[MAX];
int n,p1,p2,p3,t1,t2,s;
void process(void) {
	s=0;
	scanf("%d",&n);
	scanf("%d",&p1);
	scanf("%d",&p2);
	scanf("%d",&p3);
	scanf("%d",&t1);
	scanf("%d",&t2);
	int i;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&l[i]);
		scanf("%d",&r[i]);
		s=s+(r[i]-l[i])*p1;
	}
	for (i=1;i<n;i=i+1) {
		if (l[i+1]-r[i]<=t1) s=s+p1*(l[i+1]-r[i]);
		else {
			s=s+t1*p1;
			if (l[i+1]-r[i]<=t1+t2) s=s+p2*(l[i+1]-r[i]-t1);
			else {
				s=s+t2*p2;
				s=s+p3*(l[i+1]-r[i]-t1-t2);
			}
		}
	}
	printf("%d",s);
}
int main(void) {
	process();
	return 0;
}