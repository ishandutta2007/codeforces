#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000000
using namespace std;
int n;
int fib[200005];
int fibs[200005];
int a[600000],b[600000],tag[600000];

void pu(int rt,int l){
	a[rt]=(a[rt<<1]+1ll*a[rt<<1|1]*(l==1?0:fib[l-2])+1ll*b[rt<<1|1]*fib[l-1])%mo;
	b[rt]=(b[rt<<1]+1ll*a[rt<<1|1]*fib[l-1]+1ll*b[rt<<1|1]*fib[l])%mo;
}
void build(int l,int r,int rt){
	if(l==r){
		int x;scanf("%d",&x);
		a[rt]=b[rt]=x;
		tag[rt]=0;
	}else{
		int mid=l+r>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		pu(rt,mid-l+1);
	}
}
void add(int rt,int d,int l){
	tag[rt]+=d;if(tag[rt]>=mo)tag[rt]-=mo;	
	a[rt]=(a[rt]+1ll*d*fibs[l-1])%mo;
	b[rt]=(b[rt]+1ll*d*(fibs[l]-1))%mo;
}
void pd(int rt,int l){
	if(tag[rt]){
		int rs=l/2,ls=l-rs;
		add(rt<<1,tag[rt],ls);
		add(rt<<1|1,tag[rt],rs);
		tag[rt]=0;
	}
}
int I,v;
void upd(int l,int r,int rt){
	if(l==r){
		a[rt]=b[rt]=v;
	}else{
		pd(rt,r-l+1);
		int mid=l+r>>1;
		if(I<=mid)upd(l,mid,rt<<1);
		else upd(mid+1,r,rt<<1|1);
		pu(rt,mid-l+1);
	}
}
int l1,r1;
void upd2(int l,int r,int rt){
	if(l1<=l && r<=r1){
		add(rt,v,r-l+1);
	}else{
		pd(rt,r-l+1);
		int mid=l+r>>1;
		if(l1<=mid)upd2(l,mid,rt<<1);
		if(r1>mid)upd2(mid+1,r,rt<<1|1);
		pu(rt,mid-l+1);
	}
}
int aa,bb,le;
void que(int l,int r,int rt){
	if(l1<=l && r<=r1){
		if(le==0){
			aa=a[rt],bb=b[rt],le=r-l+1;
		}else{
			int la=aa,lb=bb;
			aa=(la+1ll*a[rt]*(le==1?0:fib[le-2])+1ll*b[rt]*fib[le-1])%mo;
			bb=(lb+1ll*a[rt]*fib[le-1]+1ll*b[rt]*fib[le])%mo;
			le+=r-l+1;
		}
	}else{
		pd(rt,r-l+1);
		int mid=l+r>>1;
		if(l1<=mid)que(l,mid,rt<<1);
		if(r1>mid)que(mid+1,r,rt<<1|1);
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	fib[0]=fib[1]=1;
	for (int i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>=mo)fib[i]-=mo;
	}
	fibs[0]=fib[0];
	for (int i=1;i<=n;i++){
		fibs[i]=fibs[i-1]+fib[i];
		if(fibs[i]>=mo)fibs[i]-=mo;
	}
	build(1,n,1);
	while(m--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&I,&v);
			upd(1,n,1);
		}else if(opt==3){
			scanf("%d%d%d",&l1,&r1,&v);
			upd2(1,n,1);
		}else{
			aa=bb=le=0;
			scanf("%d%d",&l1,&r1);
			que(1,n,1);
			printf("%d\n",aa);
		}
	}
	return 0;
}