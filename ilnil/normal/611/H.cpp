#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=1000;
int n,x,y,d,e[9][9];
int ct[9],h[9],fa[9],dl[9],sz[9],w[9];
string s;
vector<int>e2[9];
struct max_flow{
	int la[N],ne[N],to[N],l[N],h[N],d[N],st[N],js,S,T;
	void init(int ss,int tt){
		js=1;
		S=ss;T=tt;
		fo(i,0,T)la[i]=0;
	}
	void link(int x,int y,int z){
		ne[++js]=la[x];la[x]=js;to[js]=y;l[js]=z;
		ne[++js]=la[y];la[y]=js;to[js]=x;l[js]=0;
	}
	bool is(){
		fo(i,0,T)st[i]=la[i],h[i]=-1;
		h[S]=0;d[1]=S;
		for(int s=0,t=1,x;x=d[++s],s<=t;)
			for(int i=la[x];i;i=ne[i])
				if(l[i]&&h[to[i]]==-1)
					h[to[i]]=h[x]+1,d[++t]=to[i];
		return h[T]>-1;
	}
	int dinic(int x,int su){
		if(x==T)return su;int us=0;
		for(int i=st[x];i;i=ne[i])if(l[i]&&h[to[i]]==h[x]+1){
			st[x]=i;int tt=dinic(to[i],min(l[i],su-us));
			if(tt){
				l[i]-=tt;l[i^1]+=tt;us+=tt;
				if(us==su)return us;
			}
		}
		h[x]=-1;
		return us;
	}
	int flow(){
		int tot=0;
		for(;is();)tot+=dinic(S,1e6);
		return tot;
	}
}A;
void dfs(int x){
	if(x>d){
		int l=0,r=1;dl[1]=1;
		for(;y=dl[++l],l<=r;)
			for(int i:e2[y])
				dl[++r]=i;
		if(r<d)return;
		int g=d*(d+1)/2,g2=0;
		A.init(0,g+d+1);
		fo(i,1,d)
			fo(j,i,d){
				++g2;
				A.link(0,g2,e[i][j]);
				A.link(g2,g+i,e[i][j]);
				A.link(g2,g+j,e[i][j]);
			}
		fo(i,1,d)A.link(g+i,g+d+1,sz[i]);
		if(A.flow()!=n-d)return;
		fo(i,2,d)printf("%d %d\n",h[i],h[fa[i]]);
		g2=0;
		fo(i,1,d)
			fo(j,i,d){
				++g2;
				for(int k=A.la[g2];k;k=A.ne[k]){
					int dt=e[i][j]-A.l[k];
					if(A.to[k]==g+i){
						fo(l,1,dt)printf("%d %d\n",h[j],++w[i]);
						continue;
					}
					if(A.to[k]==g+j){
						fo(l,1,dt)printf("%d %d\n",h[i],++w[j]);
					}
				}
			}
		exit(0);
	}
	fo(i,1,d)if(i!=x){
		int a=i,b=x;
		if(a>b)swap(a,b);
		if(!e[a][b])continue;
		e2[i].push_back(x);
		--e[a][b];
		fa[x]=i;
		dfs(x+1);
		++e[a][b];
		e2[i].pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,2,n){
		cin>>s;x=s.length();
		cin>>s;y=s.length();
		if(x>y)swap(x,y);
		++e[x][y];
	}
	for(x=n;x;x/=10)++d;
	w[1]=h[1]=1;
	fo(i,2,d+1)w[i]=h[i]=h[i-1]*10;
	h[d+1]=n+1;
	fo(i,1,d)sz[i]=h[i+1]-h[i]-1;
	dfs(2);
	printf("-1");
}