#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define pb push_back
using namespace std;
const int N=2e5+5;
int n,ans,mx,mxh,mnh,h,now,pmx,pnow,dl,dr,dp;
int a[N],pre[N];
vector<int>p[N];
struct Seg{int l,r,be,is;}d[N+N];
#define nx()(min(p[mx][pmx],p[now][pnow])-1)
void upd(int h,int x){
	if(h<d[dp].l)--dp;
	if(h>d[dp].r)++dp;
//	if(pmx>=p[mx].size()||pnow>=p[now].size()){
//		int kk=0;
//	}
	if(d[dp].is)ans=max(ans,nx()-p[mx][h+d[dp].be]);
	else ans=max(ans,nx()-d[dp].be);
}
void doit(int l,int r){
	ff(i,l,r)if(++h>mxh){
		d[++dr]=(Seg){h,h+(r-i-1),-h+i,1};
		h=mxh=d[dr].r;
		pmx=r;
		break;
	}else ++pmx,upd(h,p[mx][i]);
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]),p[a[i]].pb(i);
	fo(i,1,n)if(p[i].size()>p[mx].size())mx=i;
	int las=1;
	p[mx].pb(n+1);
	ff(i,0,p[mx].size()){
		ff(j,las,p[mx][i])pre[j]=i;
		las=p[mx][i]+1;
	}
	fo(i,1,n)if(i!=mx&&p[i].size()){
		now=i;
		mnh=mxh=h=0;
		pmx=pnow=0;
		p[i].pb(n+1);
		dp=dl=dr=n;
		d[n]=(Seg){0,0,0,0};
		int las=0;
		ff(k,0,p[i].size()-1){
			int j=p[i][k],las2=pre[j];
			doit(las,las2);
			++pnow;
			if(--h<mnh)mnh=h,d[--dl]=(Seg){h,h,j,0};
			else upd(h,j);
			las=las2;
		}
		doit(las,p[mx].size()-1);
	}
	printf("%d\n",ans);
}