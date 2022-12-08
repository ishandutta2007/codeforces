#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=4e5+5;
int n,m;
struct Edge{
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
	bool operator<(const Edge b)const{return w<b.w;}
}e[M];
int fa[N];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int u,v,w,i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[i]=(Edge){u,v,w};
	}
	sort(e+1,e+m+1);
	int ans=0;
	for(int u=1;u<=m;){
		int v=u;
		while(v+1<=m&&e[v+1].w==e[u].w)v++;
		for(int i=u;i<=v;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x^y)ans++;
		}
		for(int i=u;i<=v;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y)fa[x]=y;
		}
		u=v+1;
	}
	ans-=(n-1);
	cout<<ans<<endl;
}