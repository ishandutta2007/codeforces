#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxT=1e4+5,maxb=3.2e7+5,W=3.2e7;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxb];
int len;
int p[maxb];
bool res[maxT];
pair<pair<ll,ll>,int> q[maxT];
int c;
ll pr[20];
void fac(ll x){
	c=0;
	int lim=sqrt(x);
	for(int i=1;i<=len;i++){
		if(p[i]>lim)break;
		if(x%p[i])continue;
		pr[++c]=p[i];
		while(x%p[i]==0)x/=p[i];
	}
	if(x>1)pr[++c]=x;
	return ;
}
const int maxx=1e5+5;
struct Edge{int to;ll w;int nxt;}e[maxx*20];
int cnt;
int head[maxx];
void add(int u,int v,ll w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
const ll inf=0x3f3f3f3f3f3f3f3f;
ll dis[maxx];
bool vis[maxx];
namespace short_path{
	priority_queue<pair<ll,int>> q;
	void dijkstra(int n){
		for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
		q.push(make_pair(0,0));dis[0]=vis[0]=0;
		while(q.size()){
			int k=q.top().se;
			q.pop();
			if(vis[k])continue;
			vis[k]=1;
			for(int i=head[k];i!=-1;i=e[i].nxt){
				int tmp=e[i].to;
				if(dis[tmp]<=dis[k]+e[i].w)continue;
				dis[tmp]=dis[k]+e[i].w;
				q.push(make_pair(-dis[tmp],tmp));
			}
		}
		return ;
	}
};
inline int add(int x,int mod){return x>=mod?x-mod:x;}
void solve(){
	int x=pr[1];
	cnt=0;for(int i=0;i<x;i++)head[i]=-1;
	for(int i=2;i<=c;i++){
		int w=pr[i]%x;
		for(int u=0;u<x;u++)add(u,add(u+w,x),pr[i]);
	}
	short_path::dijkstra(x-1);
	return ;
}
__int128 a,b;
ll exgcd(ll x,ll y){
	if(!y){a=1;b=0;return x;}
	ll g=exgcd(y,x%y),tmp=a;
	a=b;b=tmp-b*(x/y);
	return g;
}
int main(){
	for(int i=2;i<=W;i++){
		if(!bj[i])p[++len]=i;
		for(int j=1;j<=len&&1ll*i*p[j]<=W;j++){
			bj[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
    int T;
	T=read();
	for(int i=1;i<=T;i++){
		ll n,k;
		n=read();k=read();
		q[i]=make_pair(make_pair(k,n),i);
	}
	sort(q+1,q+T+1);
	ll pre=0;
	for(int i=1;i<=T;i++){
		ll k=q[i].fi.fi,n=q[i].fi.se;
		int id=q[i].se;
		if(k^pre){
			fac(k),pre=k;
			if(c>=3)solve();
		}
		if(c==0)res[id]=0;
		else if(c==1)res[id]=(n%k==0);
		else if(c==2){
			ll x=pr[1],y=pr[2];
			ll g=exgcd(x,y);
			if(a>=0&&b>=0)res[id]=1;
			else{
				a*=n;b*=n;
				if(a<0)res[id]=(b-x*(-a/y+(-a%y>0))>=0);
				else res[id]=(a-y*(-b/x+(-b%x>0))>=0);
			}
		}
		else res[id]=(dis[n%pr[1]]<=n);
	}
	for(int i=1;i<=T;i++)res[i]?puts("YES"):puts("NO");
    return 0;
}