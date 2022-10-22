//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2005,maxm=1e5+5;
const ll inf=1e18;
struct Edge{int to,w,nxt;}e[2*maxm];
int cnt,head[maxn];
int n,m,s,t;
int v[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
bool vis[maxn];
ll dis1[maxn],dis2[maxn];
struct que{
	int id;ll d;
	bool operator <(que i)const{return d>i.d;}
};
priority_queue<que> q;
void dijkstra(int s,ll *dis){
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	dis[s]=0;q.push((que){s,0});
	while(q.size()){
		int k=q.top().id;
		q.pop();
		if(vis[k])continue;
		vis[k]=1;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to,w=e[i].w;
			if(dis[tmp]<=dis[k]+w)continue;
			dis[tmp]=dis[k]+w;
			q.push((que){tmp,dis[tmp]});
		}
	}
	return ;
}
pair<ll,int> buf[maxn];
ll a[maxn][maxn];
int b[maxn][maxn];
ll f[2][maxn][maxn];
ll suf[maxn];
inline ll calc_a(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2)return 0;
	return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
inline int calc_b(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2)return 0;
	return b[x2][y2]-b[x2][y1-1]-b[x1-1][y2]+b[x1-1][y1-1];
}
int main(){
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=n;i++)v[i]=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w),add(v,u,w);
	}
	dijkstra(s,dis1);
	dijkstra(t,dis2);
	int w1=0,w2=0;
	for(int i=1;i<=n;i++)buf[i]=make_pair(dis1[i],i);
	sort(buf+1,buf+n+1);buf[0].fi=-1;
	for(int i=1;i<=n;i++){
		if(buf[i].fi>buf[i-1].fi)w1++;
		dis1[buf[i].se]=w1;
	}
	for(int i=1;i<=n;i++)buf[i]=make_pair(dis2[i],i);
	sort(buf+1,buf+n+1);buf[0].fi=-1;
	for(int i=1;i<=n;i++){
		if(buf[i].fi>buf[i-1].fi)w2++;
		dis2[buf[i].se]=w2;
	}
	for(int i=1;i<=n;i++)a[dis1[i]][dis2[i]]+=v[i],b[dis1[i]][dis2[i]]++;
	for(int i=1;i<=w1;i++)
		for(int j=1;j<=w2;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1],
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	for(int j=1;j<=w2;j++)suf[j]=calc_a(1,j,w1,w2);
	for(int i=w1;i>=1;i--){
		ll mn=-calc_a(i,1,w1,w2);
		if(!calc_b(i,1,w1,w2))continue;
		for(int j=w2;j>=1;j--){
			if(calc_b(i,j,i,w2))f[0][i][j]=suf[j]-calc_a(1,j,i-1,w2);
			else f[0][i][j]=f[0][i+1][j];
			if(calc_b(i,j,w1,j))f[1][i][j]=mn+calc_a(i,1,w1,j-1);
			else f[1][i][j]=f[1][i][j+1];
			suf[j]=max(suf[j],f[1][i][j]+calc_a(1,j,i-1,w2));
			mn=min(mn,f[0][i][j]-calc_a(i,1,w1,j-1));
		}
	}
	if(f[0][1][1]>0)puts("Break a heart");
	else if(f[0][1][1]==0)puts("Flowers");
	else puts("Cry");
    return 0;
}