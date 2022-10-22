#include<bits/stdc++.h>
#define rgi register int
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
typedef long long ll;
using namespace std;
const int N=100010;
int n,q,G,R,P,mi[N<<6],ls[N<<6],rs[N<<6],C,rt,nx;
ll d[N],f[N];
#define mid ((l+r)>>1)
void upd(int x,int v,int& k=rt,int l=0,int r=P-1){
	if(l>x||r<x)return;
	mi[k?k:k=++C]=v;
	if(l!=r)upd(x,v,ls[k],l,mid),upd(x,v,rs[k],mid+1,r);
}
int qry(int x,int y,int k=rt,int l=0,int r=P-1){
	if(l>y||r<x||!k)return n+1;
	if(l>=x&&r<=y)return mi[k];
	return min(qry(x,y,ls[k],l,mid),qry(x,y,rs[k],mid+1,r));
}
int find(ll x){return min(qry(x-R,x-1),qry(x+G,x+P-1));}
ll calc(ll x,int w){return w>n?x:ceil(x*1.0/P)*P;}
signed main(){
	scanf("%d%d%d",&n,&G,&R),P=G+R,mi[0]=n+1;
	FOR(i,1,n+1)scanf("%lld",d+i),d[i]+=d[i-1];
	ROF(i,n,1){
		nx=find(d[i]%P);
		f[i]=f[nx]+calc(d[nx]-d[i],nx);
		upd(d[i]%P,i);
	}
	for(scanf("%d",&q);q--;){
		scanf("%lld",d),nx=find((P-d[0]%P)%P);
		printf("%lld\n",f[nx]+calc(d[nx]+d[0],nx));
	}
	return 0;
}