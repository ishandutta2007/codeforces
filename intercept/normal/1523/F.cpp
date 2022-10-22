#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int S=1<<14;
int n,m,ans;
ll d[120][S],f[109][S];
int g[109][S];
struct P{int x,y,t;}p[120];
ll dis(int i,int j){return 1ll*abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=n;i<n+m;++i)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
	sort(p+1,p+n+m,[&](const P&l,const P&r){return l.t<r.t;});
	for(int s=0,T=1<<n;s<T;++s){
		for(int i=0;i<=m;++i)f[i][s]=1ll<<50,g[i][s]=-1;
		for(int i=0;i<n+m;++i)d[i][s]=1ll<<50;
		for(int i=0;i<n+m;++i){
			for(int j=0;j<n;++j)if(s>>j&1)d[i][s]=min(d[i][s],dis(i,j));
		}
	}
	for(int i=0;i<n;++i)f[0][1<<i]=0;
	for(int i=0;i<m;++i)g[i][0]=1;
	for(int s=0,T=1<<n;s<T;++s){
		//f[i][s] answer==i min time
		//d[i][s] dis->i
		//dp[i][s] s arrival i max answer
		for(int i=0;i<=m;++i){
			if(f[i][s]==1ll<<50)continue;
			for(int j=0;j<n;++j)if(!(s>>j&1))f[i][s|(1<<j)]=min(f[i][s|(1<<j)],f[i][s]+d[j][s]);
			for(int j=0;j<m;++j){
				if(f[i][s]+d[j+n][s]<=p[j+n].t)g[j][s]=max(g[j][s],i+1);
			}
		}
		for(int i=0;i<m;++i){
			if(g[i][s]<0)continue;
			for(int j=i+1;j<m;++j)if(p[i+n].t+min(d[j+n][s],dis(i+n,j+n))<=p[j+n].t){
				g[j][s]=max(g[j][s],g[i][s]+1);
			}
			for(int j=0;j<n;++j){
				if(!(s>>j&1))f[g[i][s]][s|(1<<j)]=min(f[g[i][s]][s|(1<<j)],p[i+n].t+min(dis(i+n,j),d[j][s]));
			}	
			for(int i=0;i<m;++i)ans=max(ans,g[i][s]);
		}
	}
	printf("%d\n",ans);
	return 0;
}