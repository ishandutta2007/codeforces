#include<bits/stdc++.h>
#define MAX   1000005
int a[MAX+7];
int c[MAX+7];
int s[MAX+7];
int n,k,mina;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	int i;
	mina=MAX;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&a[i]);
		c[a[i]]++;
		minimize(mina,a[i]);
	}
	if (mina<=k+1) {
		printf("%d",mina);
		exit(0);
	}
	for (i=1;i<=MAX;i=i+1) s[i]=s[i-1]+c[i];
}
int count(const int &l,const int &r) {
	if (l>r) return (0);
	if (r>MAX) return (count(l,MAX));
	if (l==0) return (s[r]);
	return (s[r]-s[l-1]);
}
bool ok(const int &d) {
	int i;
	int ret=0;
	for (i=d;i<=MAX;i=i+d)
		ret=ret+count(i,i+k);
	return (ret==n);
}
void process(void) {
	int i;
	for (i=mina;i>=k+1;i=i-1)
		if (ok(i)) {
			printf("%d",i);
			return;
		}
	assert(false);
}
int main(void) {
	init();
	process();
	return 0;
}