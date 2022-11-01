#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
struct node{
	int mx,tag;
}
f[533333];
void mod(int x,int l,int r,int ql,int qr,int v){
	if(l>=ql&&r<=qr){
		f[x].mx+=v;
		f[x].tag+=v;
		return;
	}
	int t=(l+r)>>1;
	if(ql<=t)mod(x<<1,l,t,ql,qr,v);
	if(qr>t)mod(x<<1|1,t+1,r,ql,qr,v);
	f[x].mx=std::max(f[x<<1].mx,f[x<<1|1].mx)+f[x].tag;
}
int qry(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return f[x].mx;
	int t=(l+r)>>1,res=-1e9;
	if(ql<=t)res=std::max(res,qry(x<<1,l,t,ql,qr));
	if(qr>t)res=std::max(res,qry(x<<1|1,t+1,r,ql,qr));
	return res+f[x].tag;
}
const int N=200005;
int n,s[N],pos[N];
bool g[N];
void build(int x,int l,int r){
	f[x].tag=0;
	if(l==r)f[x].mx=-l*2;
	else{
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
		f[x].mx=std::max(f[x<<1].mx,f[x<<1|1].mx);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		build(1,0,n/2);
		for(int i=1;i<=n;i++)pos[s[i]]=i;
		for(int i=1;i<=n;i++)g[i]=0;
		int first1=n,last0=n,ans=0;
		for(int i=n;i>=2;i--){
			int x=pos[i];
			g[x]=1;
			first1=std::min(first1,x);
			while(g[last0])last0--;
			if(x!=n)mod(1,0,n/2,(x-1)/2+1,n/2,2);
			if(first1==last0+1)continue;
			int ld=i-first1,l,r,qp;
			l=first1/2+1;
			r=std::min(n/2,last0/2);
			qp=~first1&1;
			int delay=qry(1,0,n/2,l-1,r)-qry(1,0,n/2,l-1,l-1)+qp;
			ans=std::max(ans,ld+delay);
		}
		printf("%d\n",ans);
	}
}