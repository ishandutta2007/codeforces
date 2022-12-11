#include<iostream>
#include<cstdio>
#include<cstring>
#define ls (p<<1)
#define rs ((p<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
const int maxn=101000,INF=0x3f3f3f3f;
int n;
int val[maxn],cpos[maxn];
int crank[maxn],vlr[maxn],vrr[maxn],mval;
int mxi[maxn<<2],tag[maxn<<2];
void update(int p){
	mxi[p]=max(mxi[ls],mxi[rs]);
}
void pushtag(int p,int x){
	mxi[p]+=x;
	tag[p]+=x;
}
void pushdown(int p){
	if(!tag[p])return;
	pushtag(ls,tag[p]);
	pushtag(rs,tag[p]);
	tag[p]=0;
}
void modify(int p,int x,int xp,int l,int r){
	if(l==r){
		mxi[p]=max(mxi[p],x);return;
	}
	pushdown(p);
	if(xp<=mid)modify(ls,x,xp,l,mid);
	else modify(rs,x,xp,mid+1,r);
	update(p);
}
int query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr)return mxi[p];
	if(lr>r||l>rr)return -INF;
	pushdown(p);
	return max(query(ls,lr,rr,l,mid),query(rs,lr,rr,mid+1,r));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&val[i]);
		++crank[val[i]];
		mval=max(mval,val[i]);
	}
	val[0]=++mval;
	++crank[mval];
	for(int i=1;i<=mval;++i){
		crank[i]+=crank[i-1];
		vlr[i]=crank[i-1]+1;
		vrr[i]=crank[i];
	}
	for(int i=n;~i;--i)
		cpos[i]=crank[val[i]]--;
	for(int i=0;i<maxn<<2;++i)
		mxi[i]=-INF;
	modify(1,0,cpos[0],1,n+1);
	for(int i=1;i<=n;++i){
		int dmax=query(1,vlr[val[i]],vrr[val[i]],1,n+1);
		if(vlr[val[i]]>1)
			dmax=max(dmax,query(1,1,vlr[val[i]]-1,1,n+1)+1);
		if(vrr[val[i]]<n+1)
			dmax=max(dmax,query(1,vrr[val[i]]+1,n+1,1,n+1)+1);
		if(val[i]^val[i-1])pushtag(1,1);
		modify(1,dmax,cpos[i-1],1,n+1);
	}
	printf("%d\n",mxi[1]);
	return 0;
}