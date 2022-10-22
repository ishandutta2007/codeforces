#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
vector<int>g[mn];
int d1[mn],dn[mn];
void bfs(int x,int dis[mn]){
	queue<int>q;
	q.push(x);
	memset(dis,0x3f,sizeof(d1));
	dis[x]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int y:g[x])if(dis[y]==inf){
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
}
int a[mn];
int m1[mn],m2[mn];
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)cin>>a[i];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(1,d1);
	bfs(n,dn);
	for(int i=1;i<=n;i++)cerr<<d1[i]<<' ';
	cerr<<'\n';
	for(int i=1;i<=n;i++)cerr<<dn[i]<<' ';
	sort(a,a+k,[](int a,int b){return d1[a]-dn[a]<d1[b]-dn[b];});
	m1[0]=d1[a[0]];
	for(int i=1;i<k;i++)m1[i]=max(m1[i-1],d1[a[i]]);
	m2[k-1]=dn[a[k-1]];
	for(int i=k-1;i>=0;i--)m2[i]=max(m2[i+1],dn[a[i]]);
	int ans=0;
	for(int i=0;i<k-1;i++)ans=max(ans,m1[i]+m2[i+1]+1);
	ans=min(ans,d1[n]);
	printf("%d",ans);
}