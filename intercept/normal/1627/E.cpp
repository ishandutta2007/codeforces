#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m,k;
struct P{
	ll r,x,y,h;
};
vector<P>g[M];
ll p[M];
bool vis[M];
void work(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)cin>>p[i],g[i].clear(),vis[i]=0;
	for(int i=1;i<=k;++i){
		int lx,ly,rx,ry,h;
		cin>>lx>>ly>>rx>>ry>>h;
		g[lx].eb(P{ly,rx,ry,h});
	}
	queue<int>q;
	q.push(1);
	bool flag=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==n)flag=1;
		for(auto o:g[u]){
			int v=o.x;
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	if(!flag){
		puts("NO ESCAPE");
		return;
	}
	g[1].eb(P{1,0,0,0});
	for(int i=1;i<=n;++i){
		int t=g[i].size();
		sort(g[i].begin(),g[i].end(),[&](const P&l,const P&r){return l.r==r.r?l.h<r.h:l.r<r.r;});
		ll mi=1ll<<60;
		for(int j=0;j<t;++j){
			auto o=g[i][j];
			if(o.h==0){
				mi=min(mi,o.y-o.r*p[i]);
			}
			else g[o.x].eb(P{o.y,0,mi+o.r*p[i]-o.h,0});
		}
		if(i==n)cout<<mi+m*p[i]<<endl;
		sort(g[i].begin(),g[i].end(),[&](const P&l,const P&r){return l.r==r.r?l.h<r.h:l.r>r.r;});
		mi=1ll<<60;
		for(int j=0;j<t;++j){
			auto o=g[i][j];
			if(o.h==0){
				mi=min(mi,o.y-(m-o.r+1)*p[i]);
			}
			else g[o.x].eb(P{o.y,0,mi+(m-o.r+1)*p[i]-o.h,0});
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/