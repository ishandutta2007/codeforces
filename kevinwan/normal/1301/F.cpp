#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int dis[40][mn][mn];
vector<pii>pwn[40];
bool don[mn];
int a[mn][mn];
int n,m,k;
void hail(int dis[mn][mn],int x){
	memset(don,0,sizeof(don));
	memset(dis,0x3f,sizeof(a));
	queue<pii>q;
	don[x]=1;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]==x){
		dis[i][j]=0;
		q.push({i,j});
	}
	cerr<<x<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cerr<<dis[i][j]<<' ';
		cerr<<endl;
	}
	while(q.size()){
		int r=q.front().first,c=q.front().second;
		q.pop();
		if(r+1<n&&dis[r+1][c]==inf)dis[r+1][c]=dis[r][c]+1,q.push({r+1,c});
		if(c+1<m&&dis[r][c+1]==inf)dis[r][c+1]=dis[r][c]+1,q.push({r,c+1});
		if(r&&dis[r-1][c]==inf)dis[r-1][c]=dis[r][c]+1,q.push({r-1,c});
		if(c&&dis[r][c-1]==inf)dis[r][c-1]=dis[r][c]+1,q.push({r,c-1});
		if(!don[a[r][c]]){
			for(pii p:pwn[a[r][c]]){
				if(dis[p.first][p.second]==inf){
					dis[p.first][p.second]=dis[r][c]+1;
					q.push({p.first,p.second});
				}
			}
			don[a[r][c]]=1;
		}
	}
	cerr<<x<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cerr<<dis[i][j]<<' ';
		cerr<<endl;
	}
}
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
		cin>>a[i][j],a[i][j]--,pwn[a[i][j]].push_back({i,j});
	for(int i=0;i<k;i++)hail(dis[i],i);
	int q;
	cin>>q;
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		int ans=abs(c-a)+abs(d-b);
		for(int i=0;i<k;i++)ans=min(ans,dis[i][a][b]+dis[i][c][d]+1);
		printf("%d\n",ans);
	}
}