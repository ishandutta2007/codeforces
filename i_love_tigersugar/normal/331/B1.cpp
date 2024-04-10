#include<cstdio>
#define MAX   300300
int a[MAX];
int b[MAX];
int n,q;
void init(void) {
	int i,t;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		a[i]=t;
		b[t]=i;
	}	
}
void swap(int &a,int &b) {
	int sw;
	sw=a;a=b;b=sw;
}
void answer(void) {
	int i,j,t,x,y,r;
	scanf("%d",&q);
	for (i=1;i<=q;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&x);
		scanf("%d",&y);
		if (t==2) {
			b[a[y]]=x;
			b[a[x]]=y;
			swap(a[x],a[y]);
		}
		else {
			r=1;
			for (j=x+1;j<=y;j=j+1)
				if (b[j]<b[j-1]) r++;
			printf("%d\n",r);
		}
	}
}
int main(void) {
	init();
	answer();
	return 0;
}