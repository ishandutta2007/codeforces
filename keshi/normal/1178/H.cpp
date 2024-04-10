#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int inf=1e9;
typedef long long ll;
 
int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}
 
int n,a[N],b[N],to[N],ww[N],nxt[N],cc[N],tt=1,s=0,t,h[N],dis[N],cur[N],ans=0;
bool vis[N];
 
void adde(int u,int v,int w,int c) {
	to[++tt]=v,ww[tt]=w,cc[tt]=c,nxt[tt]=h[u],h[u]=tt;
	to[++tt]=u,ww[tt]=0,cc[tt]=-c,nxt[tt]=h[v],h[v]=tt;
}
 
bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	deque<int> q;q.push_back(s);dis[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop_front();vis[u]=0;
		for(int i=h[u],v;v=to[i],i;i=nxt[i])
			if(ww[i]&&dis[v]>dis[u]+cc[i]) {
				dis[v]=dis[u]+cc[i];
				if(!vis[v]) vis[v]=1,cc[i]<0?q.push_front(v):q.push_back(v);
			}
	}
	return dis[t]<inf;
}
 
int dfs(int u,int flow) {
	if(u==t) return flow;
	int ret=0; vis[u]=1;
	for(int &i=cur[u],v;v=to[i],i;i=nxt[i])
		if(!vis[v]&&ww[i]&&dis[v]==dis[u]+cc[i]) {
			int d=dfs(v,min(flow,ww[i]));
			ww[i]-=d,ww[i^1]+=d,ret+=d,flow-=d,ans+=cc[i]*d;
			if(!flow) { vis[u]=0;break; }
		}
	return ret;
}
 
bool check(int t) {
	static int id[N];
	static ll ps[N],pt[N];
	for(int i=1;i<=2*n;i++) id[i]=i;
	sort(id+1,id+2*n+1,[&](int i,int j) { return 1ll*a[i]*t+b[i]>1ll*a[j]*t+b[j]; });
	for(int i=n+1;i<=2*n;i++) pt[i-n]=1ll*a[i]*t+b[i];
	sort(pt+1,pt+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2*n;j++)
			if(b[i]>=b[id[j]]) { ps[i]=1ll*a[id[j]]*t+b[id[j]];break; }
	sort(ps+1,ps+n+1);
	for(int i=1;i<=n;i++) if(ps[i]<pt[i]) return 0;
	return 1;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin>>n;
	for(int i=1;i<=2*n;i++) a[i]=gi(),b[i]=gi();
	int l=0,r=inf;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) return puts("-1"),0;
	t=7*n+1;
	for(int i=1;i<=n;i++) {
		adde(s,i,1,0);
		adde(i,i+n+n,1,0);
		adde(i+n+n+n,i+n,1,0);
		adde(i+n,t,1,0);
	}
	static int id[N];
	for(int i=1;i<=2*n;i++) id[i]=i;
	sort(id+1,id+2*n+1,[&](int i,int j) { return b[i]<b[j]; });
	for(int i=1;i<=2*n;i++) {
		if(i>1) adde(i+4*n,i-1+4*n,2*n,0);
		adde(i+4*n,id[i]+n+n,2*n,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=2*n;j;j--) if(b[i]>=b[id[j]]) { adde(i,j+4*n,2*n,1);break; }
	for(int i=1;i<=n;i++) id[i]=i+n;
	sort(id+1,id+n+1,[&](int i,int j) { return 1ll*a[i]*l+b[i]<1ll*a[j]*l+b[j]; });
	for(int i=1;i<=n;i++) {
		if(i>1) adde(i+6*n,i-1+6*n,2*n,0);
		adde(i+6*n,id[i],2*n,0);
	}
	for(int i=1;i<=2*n;i++)
		for(int j=n;j;j--) if(1ll*a[i]*l+b[i]>=1ll*a[id[j]]*l+b[id[j]]) { adde(i+n+n,j+6*n,2*n,1);break; }
	int ret=0;
	while(spfa()) {
		memcpy(cur,h,sizeof(h));
		ret+=dfs(s,inf);
	}
	cout<<l<<' '<<ans<<endl;
	return 0;
}