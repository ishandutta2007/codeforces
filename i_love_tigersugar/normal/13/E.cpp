#include<bits/stdc++.h>
#define MAX   100100
#define MSZ   333
int pw[MAX];
int sp[MAX];
int st[MAX];
int n,m,sz;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
void recal(const int &g) {
	int f=sz*g;
	int l=min(f+sz-1,n-1);
	int i;
	for (i=l;i>=f;i=i-1) {
		if (i+pw[i]>l) {
			sp[i]=0;
			st[i]=0;
		}
		else {
			sp[i]=sp[i+pw[i]]+pw[i];
			st[i]=st[i+pw[i]]+1;
		}
	}
}
void answer(int t) {
	int res=0;
	while (true) {
		if (sp[t]==0) {
			if (t+pw[t]>=n) {
				printf("%d %d\n",t+1,res+1);
				return;
			}
			else {
				res++;
				t=t+pw[t];
			}
		}
		else {
			res+=st[t];
			t=t+sp[t];
		}
	}
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	sz=0;
	int i;
	while (sz*sz<=n) sz++;
	for (i=0;i<n;i=i+1)	scanf("%d",&pw[i]);		
	for (i=0;i<n/sz+(n%sz!=0);i=i+1) recal(i);
}
void process(void) {
	int i,t,a,b;
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&a);
		a=a-1;
		if (t==0) {
			scanf("%d",&b);
			pw[a]=b;
			recal(a/sz);
		}
		else answer(a);
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	process();
	return 0;
}