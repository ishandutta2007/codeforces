#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
const int S=262143,N=S+9;
int n,a[N],fa[N],f[N],g[N],ct,t[N],r[N];
long long ans;
vector<pair<int,int>>F;
vector<int>b[N];
int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
int Mx(int x,int y){return a[x]>a[y]?x:y;}
int get(int b,int x){return fd(f[x])==b?g[x]:f[x];}
signed main(){
	scanf("%d",&n),ct=n;
	FOR(i,1,n)scanf("%d",a+i),b[a[i]].pbk(fa[i]=i),ans-=a[i];
	b[0].pbk(++n),fa[n]=n;
	FOR(s,0,S)if(b[s].size())f[s]=b[s][0];
	else for(int i=1;i&S;i<<=1)if(i&s)f[s]=Mx(f[s],f[s^i]);
	while(ct>0){
		F.clear(),memset(r,-1,sizeof r);
		FOR(s,0,S){
			g[s]=0; 
			int bl=fd(f[s]);
			for(int k:b[s])if(fd(k)!=bl)g[s]=k;
			if(g[s])continue;
			for(int i=1;i&S;i<<=1)if(i&s)g[s]=Mx(g[s],get(bl,s^i));
		}
		FOR(i,1,n){
			int x=fd(i),y=get(x,S^a[i]);
			if(a[i]+a[y]>r[x])r[x]=a[i]+a[y],t[x]=fd(y);
		}
		FOR(i,1,n){
			int x=fd(i);
			if(t[x])F.pbk({x,t[x]}),t[x]=0;
		}
		for(auto k:F){
			int x=k.first,y=fd(k.second);
			if(fd(x)!=y)--ct,fa[y]=fd(x),ans+=r[x];
		}
	}
	printf("%lld",ans),exit(0);
}