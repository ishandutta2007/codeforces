#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define DB double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
const int N=2e5+50;
const DB eps=1e-8;
int A,B,rt,n,m,son[N],dep[N],fa[N],tp[N],s[N];
DB t,ans;
vector <int> a[N];
vector <DB> b[N];
struct O{DB l,r;};
vector <O> T[N];

struct P{DB t; int f;};
vector <P> w;

int lc[N],rc[N],ll[N],rr[N];
void up(int u){
	ll[u]=lc[u]?ll[lc[u]]:u;
	rr[u]=rc[u]?rr[rc[u]]:u;
	s[u]=s[lc[u]]+s[rc[u]]+1;
}
void split(int u,int k,int &l,int &r){
	if (!u) {l=0,r=0; return;}
	if (a[m][u-1]*t+b[m][u-1]<a[m][k]*t+b[m][k]+eps)
		l=u,split(rc[u],k,rc[u],r);
	else
		r=u,split(lc[u],k,l,lc[u]);
	up(u);
}
int SPLIT(int u){
	if (!rc[u]) return lc[u];
	rc[u]=SPLIT(rc[u]);
	up(u); return u;
}
int merg(int l,int r){
	if (!l||!r) return l+r;
	if (1ll*(s[l]+s[r])*rand()<1ll*s[l]*RAND_MAX){
		rc[l]=merg(rc[l],r); up(l); return l;
	}else{
		lc[r]=merg(l,lc[r]); up(r); return r;
	}
}
void dfs(int x,int y){
	s[x]=1; dep[x]=dep[y]+1; fa[x]=y;
	for (int i=0;i<(int)a[x].size();++i)
	if (a[x][i]!=y){
		dfs(a[x][i],x);
		s[x]+=s[a[x][i]];
		if (s[a[x][i]]>s[son[x]]) son[x]=a[x][i];
	}
}
void Dfs(int x,int y){
	if (son[x]){
		tp[son[x]]=tp[x];
		Dfs(son[x],x);
	}
	for (int i=0;i<(int)a[x].size();++i)
	if (a[x][i]!=y&&a[x][i]!=son[x]){
		tp[a[x][i]]=a[x][i]; Dfs(a[x][i],x);
	}
}
bool cmp(P u,P v){
	return fabs(u.t-v.t)<eps?u.f>v.f:u.t<v.t;
}
void jud(int p,int q){
	if (!p||!q) return;
	--p; --q;
	if (a[m][p]==a[m][q]){
		if (b[m][p]==b[m][q]) ans=min(ans,t);
		return;
	}
	DB k=(b[m][q]-b[m][p])/(a[m][p]-a[m][q]);
	if(k>=t-eps&&k<=T[m][p].r+eps&&k<=T[m][q].r+eps) ans=min(ans,k);
}
int main(){
	ans=1100000;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	tp[1]=1; Dfs(1,0);
	for(int i=1;i<=n;++i) a[i].clear();
	for(int i=1;i<=m;++i){
		DB l,r,tt,hh; int cc,u,v,p,q;
		scanf("%lf%d%d%d",&tt,&cc,&u,&v);
		p=u; q=v;
		while (tp[p]!=tp[q])
			if (dep[tp[p]]>dep[tp[q]])
				p=fa[tp[p]]; 
			else q=fa[tp[q]];
		if (dep[p]<dep[q]) q=p;
		hh=1.0*(dep[u]+dep[v]-dep[q]-dep[q])/cc+tt;
		p=u; q=v;
		while(tp[p]!=tp[q]){
			if (dep[tp[p]]>dep[tp[q]]){
				a[tp[p]].push_back(-cc);
				l=tt+1.0*(dep[u]-dep[p])/cc;
				r=l+1.0*(dep[p]-dep[tp[p]]+1)/cc;
				b[tp[p]].push_back(dep[p]+l*cc);
				T[tp[p]].push_back((O){l,r});
				p=fa[tp[p]];
			}
			else{
				a[tp[q]].push_back(cc);
				r=hh-1.0*(dep[v]-dep[q])/cc,
				l=r-1.0*(dep[q]-dep[tp[q]]+1)/cc;
				b[tp[q]].push_back(dep[q]-r*cc);
				T[tp[q]].push_back((O){l,r});
				q=fa[tp[q]];
			}
		}
		a[tp[p]].push_back(dep[p]<dep[q]?cc:-cc);
		l=tt+1.0*(dep[u]-dep[p])/cc,
		r=l+1.0*abs(dep[q]-dep[p])/cc;
		b[tp[p]].push_back(dep[p]-l*(dep[p]<dep[q]?cc:-cc));
		T[tp[p]].push_back((O){l,r});
	}
	for(m=1;m<=n;++m){
		for(int j=0;j<(int)a[m].size();++j){
			w.push_back((P){T[m][j].l,j+1});
			w.push_back((P){T[m][j].r,-j-1});
		}
		sort(w.begin(),w.end(),cmp);
		rt=0;
		for(int j=0;j<(int)w.size();++j){
			t=w[j].t;
			if (ans<=t+eps) break;
			if (w[j].f>0){
				lc[w[j].f]=rc[w[j].f]=0; s[w[j].f]=1;
				ll[w[j].f]=rr[w[j].f]=w[j].f;
				split(rt,w[j].f-1,A,B);
				jud(rr[A],w[j].f);
				jud(ll[B],w[j].f);
				rt=merg(merg(A,w[j].f),B);
			}
			else{
				w[j].f*=-1;
				split(rt,w[j].f-1,A,B);
				A=SPLIT(A);
				jud(rr[A],ll[B]);
				rt=merg(A,B);
			}
		}
		w.clear();
	}
	if(ans>1000000) puts("-1");
	else printf("%.7lf\n",ans);
	return 0;
}