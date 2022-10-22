#include<bits/stdc++.h>
#define seg int k=1,int l=1,int r=n
#define mid ((l+r)>>1)
#define lc k<<1
#define rc lc|1
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=b;i>=a;--i)
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,a[N],m,L,R;
vector<pair<int,int>>q[N];
int qx[N],*A=qx,qm[N],*B=qm;
int mn[N<<2],ct[N<<2],ad[N<<2],tg[N<<2];
ll su[N<<2],ans[N];
void add(int x,int v){mn[x]+=v,ad[x]+=v;}
void pad(int k){if(ad[k])add(lc,ad[k]),add(rc,ad[k]),ad[k]=0;}
void chg(int x,int v,int d){
	if(d&&!mn[x])su[x]+=1ll*ct[x]*d,tg[x]+=d,pad(x);
	add(x,v);
}
void pdown(int k){
	chg(lc,ad[k],tg[k]),chg(rc,ad[k],tg[k]),ad[k]=tg[k]=0;
}
void build(seg){
	ct[k]=r-l+1;
	if(l==r)scanf("%d",a+l);
	else build(lc,l,mid),build(rc,mid+1,r);
}
void pup(int k){
	mn[k]=min(mn[lc],mn[rc]),ct[k]=0,su[k]=su[lc]+su[rc];
	if(mn[lc]==mn[k])ct[k]=ct[lc];
	if(mn[rc]==mn[k])ct[k]+=ct[rc];
}
void upd(int x,int y,int v,int d=0,seg){
	if(l>y||r<x)return;
	if(l>=x&&r<=y)return chg(k,v,d);
	pdown(k),upd(x,y,v,d,lc,l,mid),upd(x,y,v,d,rc,mid+1,r),pup(k);
}
ll qry(int x,seg){
	if(r<x)return 0;
	if(l>=x)return su[k];
	return pdown(k),qry(x,lc,l,mid)+qry(x,rc,mid+1,r);
}
int main(){
	scanf("%d",&n),build(),scanf("%d",&m);
	FOR(i,1,m)scanf("%d%d",&L,&R),q[R].emplace_back(L,i);
	FOR(i,1,n){
		for(upd(1,i-1,-1);A!=qx&&a[*A]<a[i];--A)upd(1+A[-1],i-1,a[i]-a[*A]);
		for(*++A=i;B!=qm&&a[*B]>a[i];--B)upd(1+B[-1],i-1,a[*B]-a[i]);
		*++B=i,upd(1,i,0,1);
		for(auto k:q[i])ans[k.second]=qry(k.first);
	}
	FOR(i,1,m)printf("%lld\n",ans[i]);
	return 0;
}