#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n;
struct data{
	int ls,rs,is,su;
	int lsi,rsi,isl,isr;
	void rev(){
		ls*=-1;rs*=-1;is*=-1;su*=-1;
	}
};
bool gtr(int i,int j){return i>j;}
bool les(int i,int j){return i<j;}
data comb(const data&a,const data&b,bool cmp(int,int)){
	data c;
	if(cmp(a.ls,a.su+b.ls)) c.ls=a.ls,c.lsi=a.lsi;
	else c.ls=a.su+b.ls,c.lsi=b.lsi;
	if(cmp(b.rs,b.su+a.rs)) c.rs=b.rs,c.rsi=b.rsi;
	else c.rs=b.su+a.rs,c.rsi=a.rsi;
	c.is=a.rs+b.ls;c.isl=a.rsi,c.isr=b.lsi;
	if(cmp(a.is,c.is))c.is=a.is,c.isl=a.isl,c.isr=a.isr;
	if(cmp(b.is,c.is))c.is=b.is,c.isl=b.isl,c.isr=b.isr;
	c.su=a.su+b.su;
	return c;
}
struct seg{
	data ma,mi;
	int tag;
}t[300000];
void rev(int x){
	t[x].tag*=-1;
	swap(t[x].ma,t[x].mi);
	t[x].ma.rev();
	t[x].mi.rev();
}
void pd(int x){
	if(t[x].tag==-1){
		rev(x<<1);
		rev(x<<1|1);
		t[x].tag=1;
	}
}
void pu(int x){
	t[x].ma=comb(t[x<<1].ma,t[x<<1|1].ma,gtr);
	t[x].mi=comb(t[x<<1].mi,t[x<<1|1].mi,les);
}
void build(int l,int r,int x){
	if(l==r){
		int tm;
		scanf("%d",&tm);
		t[x].tag=1;		
		t[x].ma=(data){tm,tm,tm,tm,l,l,l,l};
		t[x].mi=(data){0,0,0,tm,l-1,l+1,l+1,l-1};
		if(tm<0)swap(t[x].ma,t[x].mi);			
	}else{
		int mid=l+r>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		t[x].tag=1;
		pu(x);
	}
}
int I,v;
void upd(int l,int r,int x){
	if(l==r){
		t[x].ma=(data){v,v,v,v,l,l,l,l};
		t[x].mi=(data){0,0,0,v,l-1,l+1,l+1,l-1};
		if(v<0)swap(t[x].ma,t[x].mi);
	}else{
		pd(x);
		int mid=l+r>>1;
		if(I<=mid)upd(l,mid,x<<1);
		else upd(mid+1,r,x<<1|1);
		pu(x);
	}
}
int l1,r1,bo;data ans;
int cl[25],cr[25],ctot;
void query(int l,int r,int x){
	if(l1<=l && r<=r1){
		if(!bo)ans=t[x].ma,bo=1;
		else ans=comb(ans,t[x].ma,gtr);
	}else{
		pd(x);
		int mid=l+r>>1;
		if(l1<=mid)query(l,mid,x<<1);
		if(r1>mid)query(mid+1,r,x<<1|1);
	}
}
void modi(int l,int r,int x){
	if(l1<=l && r<=r1)rev(x);
	else{
		int mid=l+r>>1;
		pd(x);
		if(l1<=mid)modi(l,mid,x<<1);
		if(r1>mid)modi(mid+1,r,x<<1|1);
		pu(x);
	}
}
int work(int l,int r,int k){
	ctot=0;
	int an=0;
	for (int i=1;i<=k;i++){
		l1=l,r1=r,bo=0;
		query(1,n,1);
		if(ans.is<=0)break;
		an+=ans.is;
		++ctot;
		l1=cl[ctot]=ans.isl;
		r1=cr[ctot]=ans.isr;
		modi(1,n,1);
	}
	for (int i=ctot;i>=1;i--){
		l1=cl[i];r1=cr[i];
		modi(1,n,1);
	}
	return an;
}
int main()
{
	scanf("%d",&n);
	build(1,n,1);
	int que;scanf("%d",&que);
	while(que--){
		int opt;scanf("%d",&opt);
		if(opt==0){
			scanf("%d%d",&I,&v);
			upd(1,n,1);
		}else{
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",work(l,r,k));
		}
	}
	return 0;
}