#include<cstdio>
#define MAX   1111
int a[MAX];
int b[MAX];
bool o[MAX];
int p[MAX];
int n,r;
void init(void) {
	scanf("%d",&n);
	int i;
	for (i=1;i<=1010;i=i+1) {
		o[i]=false;
		p[i]=0;		
	}
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		if (a[i]!=b[i]) o[b[i]]=true;
		if (a[i]==b[i]) {
			if (p[b[i]]==0) {
				p[b[i]]=i;
				continue;
			}
			if (p[b[i]]>0) {
				p[b[i]]=-1;
				continue;
			}
		}	
	}
	r=n;
	for (i=1;i<=n;i=i+1) {
		if (o[a[i]]) {
			r--;
			continue;
		}
		if (p[a[i]]<0) {
			r--;
			continue;
		}
		if ((p[a[i]]>0) && (i!=p[a[i]])) {
			r--;
			continue;
		}
	}		
	printf("%d",r);
}
int main(void) {
	init();
	return 0;
}