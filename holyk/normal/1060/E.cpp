#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');return p?-w:w;
}
inline bool smin(int&x,const int&y){return x>y?x=y,1:0;}
inline bool smax(int&x,const int&y){return x<y?x=y,1:0;}
const int N=2e5+5;
vector<int>g[N];
int rt,msz,sum,siz[N];
bool vis[N];
inline void findrt(int x){
	vis[x]=1;siz[x]=1;
	int mx=0;
	for(int y:g[x])if(!vis[y])
	findrt(y),siz[x]+=siz[y],smax(mx,siz[y]);
	smax(mx,sum-siz[x]);
	if(smin(msz,mx))rt=x;vis[x]=0;
}
ll d[2],ans;
int n,c[2];
inline void go1(int x,int dis){
	vis[x]=1;siz[x]=1;
	if(dis&1)ans+=d[0]+d[1]+1ll*(dis+1>>1)*(c[0]+c[1]);
	else ans+=d[0]+1ll*c[0]*(dis>>1)+d[1]+1ll*c[1]*(dis/2+1);
	for(int y:g[x])if(!vis[y])go1(y,dis+1),siz[x]+=siz[y];
	vis[x]=0;
}
inline void go2(int x,int dis){
	vis[x]=1;
	d[dis&1]+=dis>>1,++c[dis&1];
	for(int y:g[x])if(!vis[y])go2(y,dis+1);
	vis[x]=0;
}
inline void solve(int x){
	vis[x]=1;d[0]=0,c[0]=1;
	for(int y:g[x])if(!vis[y])go1(y,1),go2(y,1);
	d[0]=d[1]=c[0]=c[1]=0;
	for(int y:g[x])if(!vis[y]){
		msz=n+1,sum=siz[y],findrt(y),solve(rt);
	}
}
#define pb push_back
int main(){
	n=read();
	REP(i,2,n){
		int x=read(),y=read();g[x].pb(y),g[y].pb(x);
	}
	msz=sum=n;findrt(1);
	solve(rt);
	cout<<ans;
	return 0;
}