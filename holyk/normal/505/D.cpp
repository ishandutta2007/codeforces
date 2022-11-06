#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c;int w;
	while(!isdigit(c=getchar()));w=c&15;
	while(isdigit(c=getchar()))w=w*10+(c&15);return w;
}
inline char smax(int&x,const int&y){return x<y?x=y,1:0;}
inline char smin(int&x,const int&y){return x>y?x=y,1:0;}
const int N=2e5+5;
vector<int>g[N],e[N];
int n,m,vis[N],l,r,t[N],d[N],q[N];
#define pb push_back
inline void go(int x){vis[x]=1;t[++t[0]]=x;for(int y:g[x])if(!vis[y])go(y);}
inline int solve(){
	REP(i,1,t[0])for(int y:e[t[i]])++d[y];l=1,r=0;
	REP(i,1,t[0])if(!d[t[i]])q[++r]=t[i];
	while(l<=r)for(int y:e[q[l++]])if(!--d[y])q[++r]=y;
	return r==t[0];
}
int main(){
	n=read(),m=read();
	while(m--)l=read(),g[l].pb(r=read()),g[r].pb(l),e[l].pb(r);
	int ans=0;
	REP(i,1,n)if(!vis[i])t[0]=0,go(i),ans+=t[0]-solve();
	cout<<ans;
	return 0;
}