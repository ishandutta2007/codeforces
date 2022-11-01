#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2005;
const ll inf=1e18;
int n,m,s,t,a[N],x,y,l;
vector<P>e[N];
struct nod{
	ll f;int x;
	nod(ll u,int v){f=u;x=v;}
	bool operator<(const nod &b)const{return f>b.f;}
};
priority_queue<nod>A;
struct dis{
	ll f[N];
	int d[N],ds,di[N];
	void work(int s){
		fo(i,1,n)f[i]=inf;
		f[s]=0;A.push(nod(0,s));
		for(;!A.empty();){
			nod o=A.top();A.pop();
			if(o.f!=f[o.x])continue;
			d[++ds]=o.x;
			for(P i:e[o.x])
				if(f[i.fi]>o.f+i.se){
					f[i.fi]=o.f+i.se;
					A.push(nod(f[i.fi],i.fi));
				}
		}
		ds=1;di[d[1]]=1;
		fo(i,2,n)
			di[d[i]]=f[d[i]]==f[d[i-1]]?ds:++ds;
	}
}g[2];
bool bz[N];
struct dp{
	ll s[N],f[N];
	int gs[N],O,p;
	void init(int o,int x){
		memset(bz,0,sizeof bz);
		for(int i=1;i<=n&&g[o].di[g[o].d[i]]<=x;++i)bz[g[o].d[i]]=1;
		int j=n,cnt=0;ll su=0;
		fd(i,0,g[!o].ds){
			for(;j&&g[!o].di[g[!o].d[j]]>=i;--j)
				if(!bz[g[!o].d[j]])
					++cnt,su+=a[g[!o].d[j]];
			s[i]=su;gs[i]=cnt;
		}
		O=o;p=g[!o].ds;
		f[p+1]=O?-inf:inf;
	}
	void put(int x,ll v){
		f[x]=O?max(f[x+1],v-s[x+1]):min(f[x+1],v+s[x+1]);
	}
	ll get(int x){
		for(;gs[x+1]>gs[p+1];)--p;
		return f[p+1]+(O?s[x+1]:-s[x+1]);
	}
}h[2][N];
ll f[N][N][2],ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	fo(i,1,n)cin>>a[i];
	fo(i,1,m)cin>>x>>y>>l,e[x].push_back(P(y,l)),e[y].push_back(P(x,l));
	g[0].work(s);
	g[1].work(t);
	fo(o,0,1)fo(i,0,g[o].ds)h[o][i].init(o,i);
	fd(i,0,g[0].ds)fd(j,0,g[1].ds){
		f[i][j][0]=h[1][j].get(i);
		f[i][j][1]=h[0][i].get(j);
		if(h[0][i].gs[j+1]==0)
			f[i][j][0]=f[i][j][1]=0;
		h[1][j].put(i,f[i][j][1]);
		h[0][i].put(j,f[i][j][0]);
	}
	ans=f[0][0][0];
	printf(ans>0?"Break a heart":(ans?"Cry":"Flowers"));
}