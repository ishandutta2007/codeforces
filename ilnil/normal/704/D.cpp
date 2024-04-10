#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define P pair<int,int>
#define ll long long
#define fi first
#define se second
#define wrong return puts("-1"),0
using namespace std;
const int N=1e5+5,M=3e5+5,inf=1e9;
int n,m,r,b,t,l,d,ds,T,TT;
int x[N],y[N],wz[N];
int su[M],sum,ans;
map<int,int>d0,d1,c0,c1,b0,b1;
int la[M],st[M],h[M],dl[M],js;
struct edge{int y,l,ne;}e[N*10];
void link(int x,int y,int z){
	e[++js].ne=la[x];la[x]=js;e[js].y=y;e[js].l=z;
	e[++js].ne=la[y];la[y]=js;e[js].y=x;
}
void add(int x,int y,int le,int ri){
	su[x]+=le;su[y]-=le;
	link(x,y,ri-le);
}
bool is(int S){
	fo(i,0,TT)h[i]=-1,st[i]=la[i];
	dl[1]=S;h[S]=0;
	for(int l=0,r=1,x;x=dl[++l],l<=r;)	
		for(int i=la[x];i;i=e[i].ne)
			if(e[i].l&&h[e[i].y]==-1)
				dl[++r]=e[i].y,h[e[i].y]=h[x]+1;
	return h[TT]>-1;
}
int dinic(int x,int su){
	if(x==TT)return su;int us=0;
	for(int i=st[x];i;i=e[i].ne)if(e[i].l&&h[x]+1==h[e[i].y]){
		st[x]=i;int tt=dinic(e[i].y,min(e[i].l,su-us));
		if(tt){
			e[i].l-=tt;e[i^1].l+=tt;us+=tt;
			if(us==su)return us;
		}
	}
	h[x]=-1;
	return us;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>r>>b;js=1;T=m+n*2+1;
	fo(i,1,n)cin>>x[i]>>y[i],++c0[x[i]],++c1[y[i]];
	fo(i,1,m){
		cin>>t>>l>>d;
		if(t==1){
			if(d0.count(l))d0[l]=min(d0[l],d);else d0[l]=d;
		}else{
			if(d1.count(l))d1[l]=min(d1[l],d);else d1[l]=d;
		}
	}
	for(P i:d0){
		int c=c0[i.fi];c0.erase(i.fi);
		int le=max(c-i.se+1>>1,0),ri=min(c,i.se+c>>1);
		if(le>ri)wrong;
		b0[i.fi]=++ds;
		add(0,ds,le,ri);
	}
	for(P i:d1){
		int c=c1[i.fi];c1.erase(i.fi);
		int le=max(c-i.se+1>>1,0),ri=min(c,i.se+c>>1);
		if(le>ri)wrong;
		b1[i.fi]=++ds;
		add(ds,T,le,ri);
	}
	for(P i:c0)b0[i.fi]=++ds,add(0,ds,0,i.se);
	for(P i:c1)b1[i.fi]=++ds,add(ds,T,0,i.se);
	fo(i,1,n)add(b0[x[i]],b1[y[i]],0,1),wz[i]=js-1;
	int lasjs=js;
	link(T,0,inf);
	fo(i,0,T){
		if(su[i]<0)link(T+1,i,-su[i]);
		if(su[i]>0)link(i,T+2,su[i]),sum+=su[i];
	}
	for(TT=T+2;is(T+1);)ans+=dinic(T+1,inf);
	if(ans!=sum)wrong;
	for(;js>lasjs;js-=2){
		la[e[js].y]=e[js-1].ne;
		la[e[js-1].y]=e[js].ne;
	}
	ans=e[lasjs+2].l;
	for(TT=T;is(0);)ans+=dinic(0,inf);
	cout<<(ll)max(b,r)*(n-ans)+(ll)min(b,r)*ans<<endl;
	char p1,p2;
	if(b>r)p1='b',p2='r';else p1='r',p2='b';
	fo(i,1,n)putchar(e[wz[i]].l?p1:p2);
}