//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,inf=0x3f3f3f3f;
int h[maxn];
vec<int> e[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int f[maxn];
vec<int> t[maxn];
vec<pii> a[maxn];
queue<int> q;
int dis[maxn];
int main(){
    int n;
	n=read();
	memset(h,0x3f,sizeof(h));
	for(int i=1;i<=n;i++)if(read())q.push(i),h[i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		e[u].eb(v),e[v].eb(u);
	}
	while(q.size()){
		int k=q.front();
		q.pop();
		for(auto x:e[k]){
			if(h[x]<inf)continue;
			h[x]=h[k]+1;
			q.push(x);
		}
	}
	for(int i=1;i<=n;i++)t[h[i]].eb(i),f[i]=h[i];
	for(int i=1;i<=n;i++)for(auto j:e[i])if(h[i]==h[j])a[h[i]].eb(pii(i,j));
	for(int v=0;v<=n;v++){
		if(!a[v].size())continue;
		for(int i=1;i<=n;i++)dis[i]=inf;
		for(auto p:a[v])dis[p.fi]=dis[p.se]=0;
		for(int w=v;w<=n;w++){
			for(auto x:t[w])if(dis[x]<inf)q.push(x);
			while(q.size()){
				int k=q.front();
				q.pop();
				for(auto x:e[k]){
					if(h[x]!=h[k])continue;
					if(dis[x]<=dis[k]+1)continue;
					dis[x]=dis[k]+1;
					q.push(x);
				}
			}
			for(auto x:t[w])
				for(auto y:e[x])
					if(h[y]>h[x])
						dis[y]=min(dis[y],max(dis[x]-1,0));
		}
		for(int i=1;i<=n;i++)if(dis[i]==0)f[i]=min(f[i],v);
	}
	for(int i=1;i<=n;i++)printf("%d ",2*(h[i]-f[i])+f[i]);
	puts("");
    return 0;
}