#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1009;
int n,m,now;
int in[M],p[M],a[M],b[M];
ll ma[M];
vector<int>g[M];
queue<int>q;
void add(ll&x){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i){
		p[i]=ma[i]=0;
		if(in[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(v!=p[u]&&x+ma[u]>a[v]){
				if(p[v]||(in[v]&&!in[u])){
					while(u){
						if(!in[u])now++,x+=b[u];
						in[u]=1;
						u=p[u];
					}
					while(v){
						if(!in[v])now++,x+=b[v];
						in[v]=1;
						v=p[v];
					}
					return;
				}
				else {
					if(!p[v]&&!in[v]){
						p[v]=u,ma[v]=ma[u]+b[v],q.push(v);
					}
				}
			}
		}
	}
}
bool check(ll x){
	for(int i=1;i<=n;++i)in[i]=0;
	in[1]=now=1;
	while(1){
		int la=now;
		add(x);
		if(now==la)break;
	}
	return now==n;
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	int l=0,r=1e9;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}