#include<bits/stdc++.h>
#define ri register int
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
const int N=3e6+5;
vector<int>e[N][10],tp;
vector<vector<int> >q,qtmp;
int n,m,tot,dis[N];
bool vs[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	tot=n;
	for(ri u,v,w,pre,i=1;i<=m;++i){
		u=read(),v=read();
		w=i,pre=v;
		while(w>9){
			++tot;
			e[tot][w%10].pb(pre);
			w/=10;
			pre=tot;
		}
		e[u][w].pb(pre);
		w=i,pre=u;
		while(w>9){
			++tot;
			e[tot][w%10].pb(pre);
			w/=10;
			pre=tot;
		}
		e[v][w].pb(pre);
	}
	tp.pb(1);
	dis[1]=0,q.pb(tp),vs[1]=1;
	while(q.size()){
		qtmp.clear();
		for(ri i=0;i<q.size();++i){
			for(ri nm=0;nm<10;++nm){
				tp.clear();
				for(ri x,j=0;j<q[i].size();++j){
					x=q[i][j];
					for(ri k=0,v;k<e[x][nm].size();++k){
						if(vs[v=e[x][nm][k]])continue;
						vs[v]=1;
						dis[v]=add(mul(dis[x],10),nm);
						tp.pb(v);
					}
				}
				if(tp.size())qtmp.pb(tp);
			}
		}
		q=qtmp;
	}
	for(ri i=2;i<=n;++i)cout<<dis[i]<<'\n';
}