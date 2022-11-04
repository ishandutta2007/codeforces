#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2010;
int f[N][N];
ll dist[N][N];
int n,m,w;
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

pair<ll,ll>solve(){ // time to other, time to por
	pair<ll,ll>res={LLONG_MAX,LLONG_MAX};
	queue<pair<ll,ll>>q;q.push({0,0});
	dist[0][0]=1;
	while(q.size()){
		auto[y,x]=q.front();q.pop();
		if(f[y][x]>0)res.second=min(res.second,dist[y][x]-1+f[y][x]);
		for(int i=0;i<4;++i){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(ny>=0&&ny<n&&nx>=0&&nx<m&&!dist[ny][nx]&&f[ny][nx]>=0){
				dist[ny][nx]=dist[y][x]+w;
				q.push({ny,nx});
			}
		}
	}
	if(dist[n-1][m-1])res.first=dist[n-1][m-1]-1;
	for(int i=0;i<n/2;++i)
		for(int j=0;j<m;++j)
			swap(f[i][j],f[n-i-1][j]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m/2;++j)
			swap(f[i][j],f[i][m-j-1]);
	memset(dist,0,sizeof(dist));
	return res;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>w;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>f[i][j];
	auto r1=solve();
	auto r2=solve();
	if(r1.first==LLONG_MAX&&(r1.second==LLONG_MAX||r2.second==LLONG_MAX))cout<<-1<<endl;
	else cout<<min(r1.first,r1.second==LLONG_MAX||r2.second==LLONG_MAX?LLONG_MAX:r1.second+r2.second)<<endl;
}