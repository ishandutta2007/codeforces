#include<cstdio>
#include<cstring>
#define MAX   300300
int a[MAX];
int b[MAX];
int t[MAX];
int n,q;
void update(int u,const int &val) {
	while (1<=u && u<=n) {
		t[u]+=val;
		u=u+(u&(-u));
	}
}
int sum(int u) {
	int res=0;
	while (1<=u && u<=n) {
		res+=t[u];
		u=u&(u-1);
	}
	return (res);
}
void init(void) {
	int i,v;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&v);
		a[i]=v;
		b[v]=i;
	}
	memset(t,0,sizeof t);
	for (i=2;i<=n;i=i+1)
		if (b[i]<b[i-1]) update(i,1);	
}
void swap(int &a,int &b) {
	int sw;sw=a;a=b;b=sw;
}
void answer(void) {
	int i,t,x,y,r,t1,t2;
	bool px,py,px1,py1;
	scanf("%d",&q);
	for (i=1;i<=q;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&x);
		scanf("%d",&y);
		if (t==2) {
			t1=a[x];
			t2=a[y];
			px=(b[t1]<b[t1-1]);
			py=(b[t2]<b[t2-1]);
			px1=(b[t1+1]<b[t1]);
			py1=(b[t2+1]<b[t2]);
			b[t1]=y;
			b[t2]=x;
			swap(a[x],a[y]);
			if (b[t1]<b[t1-1] && !px) update(t1,1);
			if (b[t1]>b[t1-1] && px) update(t1,-1);
			if (b[t1+1]<b[t1] && !px1) update(t1+1,1);
			if (b[t1+1]>b[t1] && px1) update(t1+1,-1);
			if (t2!=t1 && t2!=t1+1) {
				if (b[t2]<b[t2-1] && !py) update(t2,1);
				if (b[t2]>b[t2-1] && py) update(t2,-1);				
			}
			if (t2+1!=t1 && t2+1!=t1+1) {
				if (b[t2+1]<b[t2] && !py1) update(t2+1,1);
				if (b[t2+1]>b[t2] && py1) update(t2+1,-1);
			}
		}
		else {
			r=sum(y)-sum(x);
			printf("%d\n",r+1);
		}		
	}
}
int main(void) {
	init();
	answer();
	return 0;
}