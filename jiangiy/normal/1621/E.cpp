#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=500005;
struct node{
	int v,tag;
}
f[1<<21|10];
void st(int x,int v){
	f[x].v+=v;
	f[x].tag+=v;
}
void pd(int x){
	if(f[x].tag){
		st(x<<1,f[x].tag);
		st(x<<1|1,f[x].tag);
		f[x].tag=0;
	}
}
void pu(int x){
	f[x].v=std::min(f[x<<1].v,f[x<<1|1].v);
}
void mod(int x,int l,int r,int ql,int qr,int v){
	if(l>=ql&&r<=qr){
		return st(x,v);
	}
	int t=(l+r)>>1;
	pd(x);
	if(ql<=t)mod(x<<1,l,t,ql,qr,v);
	if(qr>t)mod(x<<1|1,t+1,r,ql,qr,v);
	pu(x);
}
int n,m,vc,t[N],vs[N];
PI s[N],r[N];
void build(int x,int l,int r){
	f[x].tag=0;
	if(l==r){
		f[x].v=0;
	}
	else{
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
		pu(x);
	}
}
void modx(int v,int g){
	int x=std::lower_bound(vs+1,vs+vc+1,v)-vs;
	mod(1,1,vc,x,vc,g);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&s[i].fi),s[i].fi=-s[i].fi,s[i].se=1;
		for(int i=1;i<=n;i++)vs[i]=s[i].fi;
		vc=n;
		int totk=0;
		for(int i=1;i<=m;i++){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)scanf("%d",t+j);
			LL sum=0;
			for(int j=1;j<=k;j++)sum+=t[j];
			int u=(sum+k-1)/k;
			s[++n]=MP(-u,-1);
			vs[++vc]=-u;
			for(int j=1;j<=k;j++){
				int u2=(sum-t[j]+k-2)/(k-1);
				r[++totk]=MP(-u,-u2);
				vs[++vc]=-u2;
			}
		}
		std::sort(s+1,s+n+1);
		std::sort(vs+1,vs+vc+1);
		vc=std::unique(vs+1,vs+vc+1)-vs-1;
		build(1,1,vc);
		for(int i=1;i<=n;i++){
			modx(s[i].fi,s[i].se);
		}
		for(int i=1;i<=totk;i++){
			modx(r[i].fi,1);
			modx(r[i].se,-1);
			putchar((f[1].v>=0)+'0');
			modx(r[i].fi,-1);
			modx(r[i].se,1);
		}
		putchar(10);
	}
}