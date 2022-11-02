#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define MAXN 100600

const int inf=1000000010;

class Query {
	public:
		int id,key;
//		long double sol;
		const bool operator<(const Query &b) const {
			return key<b.key;
		}
};

int n,rt;
int pred[MAXN],key[MAXN];

bool isleaf[MAXN];
int left[MAXN],right[MAXN];
int lmost[MAXN],rmost[MAXN];

int qn,qi;
Query qr[MAXN];
long double sol[MAXN];

class StackVar {
	public:
		int v,lval,rval,d;
		long long s;
		int flag;
		StackVar() {}
		StackVar(int vi,int li,int ri,int di,long long si):
	     v(vi),lval(li),rval(ri),d(di),s(si) { flag=0; }
};
int dsn;
StackVar dst[MAXN];

inline void find(int v) {
	int f;
	dsn=0;
	dst[dsn++]=StackVar(v,0,0,0,0);
	while(dsn) {
		v=dst[dsn-1].v;
		f=dst[dsn-1].flag;
		if(!isleaf[v]) {
			if(f==0) {
				dst[dsn-1].flag=1;
				dst[dsn++]=StackVar(left[v],0,0,0,0);
				continue;
			} else if(f==1) {
				dst[dsn-1].flag=2;
				dst[dsn++]=StackVar(right[v],0,0,0,0);
				continue;
			} else {
//			find(left[v]);
//			find(right[v]);
				lmost[v]=lmost[left[v]];
				rmost[v]=rmost[right[v]];
			}
		} else {
			lmost[v]=rmost[v]=key[v];
		}
		dsn--;
	}
}

inline void dfs(int v,int lval,int rval,int d,long long s) {
	dsn=0;
	dst[dsn++]=StackVar(v,lval,rval,d,s);
	while(dsn) {
		v=dst[dsn-1].v;
		lval=dst[dsn-1].lval;
		rval=dst[dsn-1].rval;
		d=dst[dsn-1].d;
		s=dst[dsn-1].s;
		if(isleaf[v]) {
			while(qi<qn&&qr[qi].key>=lval&&qr[qi].key<=rval) {
				sol[qr[qi].id]=(long double)s/d;
				qi++;
			}
		} else {
			if(dst[dsn-1].flag==0) {
				dst[dsn-1].flag=1;
				//				dfs(left[v],lval,key[v]-1,d+1,s+lmost[right[v]]);
				dst[dsn++]=StackVar(left[v],lval,key[v]-1,d+1,s+lmost[right[v]]);
				continue;
			} else if(dst[dsn-1].flag==1) {
				dst[dsn-1].flag=2;
				dst[dsn++]=StackVar(right[v],key[v]+1,rval,d+1,s+rmost[left[v]]);
				//				dfs(right[v],key[v]+1,rval,d+1,s+rmost[left[v]]);
				continue;
			}
		}
		dsn--;
	}
}

inline void solve() {
	int i;
	find(rt);
	//	puts("--");
	//	for(i=1;i<=n;i++)
	//		printf("%d(%d,%d,%d)\n",i,(int)isleaf[i],lmost[i],rmost[i]);
	qi=0;
	std::sort(qr,qr+qn);
	dfs(rt,0,inf,0,0);
	//	puts("++");
	//	for(i=0;i<qn;i++)
	//		sol[qr[i].id]=qr[i].sol;
	//	for(i=0;i<qn;i++)
	//		printf("%.11lf\n",sol[i]);
	for(i=0;i<qn;i++)
		std::cout << std::setprecision(11) << sol[i] << std::endl;
}

int main(void)
{
	int i,v,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		isleaf[i]=1;
	for(i=1;i<=n;i++) {
		scanf("%d %d",&v,&x);
		pred[i]=v;
		key[i]=x;
		if(v<0) {
			rt=i;
			continue;
		}
		if(!isleaf[v]) {
			right[v]=i;
			if(key[left[v]]>key[right[v]]) std::swap(left[v],right[v]);
		} else {
			isleaf[v]=0;
			left[v]=i;
		}
	}
	scanf("%d",&qn);
	for(i=0;i<qn;i++) {
		qr[i].id=i;
		scanf("%d",&qr[i].key);
	}
	//	for(i=1;i<=n;i++)
	//		printf("%d(%d,%d,%d)\n",i,(int)isleaf[i],left[i],right[i]);
	solve();
}