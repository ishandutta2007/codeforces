#include<bits/stdc++.h>
#define ri register int
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
const int N=1e5+5;
int ft[N],rt[355][N],vl[N],lp[355],rp[355],mx[355],id[N],a[N],tg[355],siz[N];
int blo=300,n,m;
inline int find(int x){return x^ft[x]?ft[x]=find(ft[x]):x;}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x^y)ft[y]=x,siz[x]+=siz[y];
}
inline void build(int p){
	for(ri i=lp[p];i<=rp[p];++i){
		if(!rt[p][vl[i]])rt[p][vl[i]]=i;
		else merge(rt[p][vl[i]],i);
	}
}
inline void update(int p,int l,int r,int x){
	for(ri i=lp[p];i<=rp[p];++i)a[i]=vl[find(i)],rt[p][a[i]]=0,siz[i]=1;
	for(ri i=l;i<=r;++i)(a[i]-tg[p]>x)&&(a[i]-=x);
	for(ri i=lp[p];i<=rp[p];++i){
		vl[i]=a[i],ft[i]=i;
		if(!rt[p][vl[i]])rt[p][vl[i]]=i;
		else merge(rt[p][vl[i]],i);
	}
	while(!rt[p][mx[p]])--mx[p];
}
inline void update(int l,int r,int x){
	if(id[l]==id[r])return update(id[l],l,r,x);
	update(id[l],l,rp[id[l]],x),update(id[r],lp[id[r]],r,x);
	for(ri i=id[l]+1;i<id[r];++i){
		if(mx[i]-tg[i]>=x*2){
			for(ri j=tg[i]+1;j<=tg[i]+x;++j){
				if(!rt[i][j])continue;
				if(!rt[i][j+x])vl[rt[i][j+x]=rt[i][j]]+=x;
				else merge(rt[i][j+x],rt[i][j]);
				rt[i][j]=0;
			}
			tg[i]+=x;
		}
		else{
			for(ri j=tg[i]+x+1;j<=mx[i];++j){
				if(!rt[i][j])continue;
				if(!rt[i][j-x])vl[rt[i][j-x]=rt[i][j]]-=x;
				else merge(rt[i][j-x],rt[i][j]);
				rt[i][j]=0;
			}
			while(!rt[i][mx[i]])--mx[i];
		}
	}
}
inline int query(int p,int l,int r,int x){
	int res=0;
	for(ri i=l;i<=r;++i)res+=vl[find(i)]==x+tg[p];
	return res;
}
inline int query(int l,int r,int x){
	if(id[l]==id[r])return query(id[l],l,r,x);
	int res=query(id[l],l,rp[id[l]],x)+query(id[r],lp[id[r]],r,x);
	for(ri i=id[l]+1;i<id[r];++i)if(x+tg[i]<=mx[i])res+=siz[rt[i][x+tg[i]]];
	return res;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	blo=max(blo,(int)sqrt(n));
	for(ri l=1,r=min(n,blo),idx=1;l<=n;l+=blo,r=min(n,r+blo),++idx){
		for(ri i=l;i<=r;++i){
			id[i]=idx;
			ft[i]=i,siz[i]=1;
			mx[idx]=max(mx[idx],vl[i]=a[i]=read());
		}
		lp[idx]=l,rp[idx]=r;
		build(idx);
	}
	for(ri l,r,op,x;m;--m){
		op=read(),l=read(),r=read(),x=read();
		if(op==1)update(l,r,x);
		else cout<<query(l,r,x)<<'\n';
	}
	return 0;
}