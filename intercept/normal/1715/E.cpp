#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m,k;
vector<pii>g[M];
int q[M];
ll dis[M],dp[M];
int t[M<<1];
void push(int x,int y){
    for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=dis[t[x]]<dis[t[x^1]]?t[x]:t[x^1];
}
void dij(){
    for(int i=1;i<=n;++i)push(i,i);
    for(int i=1;i<=n;++i){
        int u=t[1];
        push(u,0);
        for(auto o:g[u]){
            int v=o.fi,w=o.se;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                push(v,v);
            }
        }
    }
}
ll get(int i){
	return dis[i]+1ll*i*i;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<=n;++i)dis[i]=1ll<<50;
	dis[1]=0;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].eb(v,w);
		g[v].eb(u,w);
	}
	dij();
	for(int o=1;o<=k;++o){
		int l=1,r=1;
		q[1]=1;
		for(int i=2;i<=n;++i){
			if(dis[i]==1ll<<50)continue;
			while(r>l&&(get(i)-get(q[r-1]))*(q[r]-q[r-1])<(get(q[r])-get(q[r-1]))*(i-q[r-1]))r--;
			q[++r]=i;
		}
		for(int i=2;i<=n;++i){
			while(r>l&&2ll*i*(q[l+1]-q[l])>get(q[l+1])-get(q[l]))l++;
			dp[i]=dis[q[l]]+1ll*(i-q[l])*(i-q[l]);
		}
		for(int i=2;i<=n;++i)dis[i]=min(dis[i],dp[i]);
		dij();
	}	
	for(int i=1;i<=n;++i)cout<<dis[i]<<" ";
	return 0;
}
/*
5 1

*/