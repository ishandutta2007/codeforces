// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include <ctime>
#define LL long long
#define ept 1e-10
#define pa pair<int,int>
using namespace std;
const int N=1000050;
const LL mod=1e9+7;
int n,m,q,ans1=0,ans2=0,ans=0;
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int u,v;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n+m;++i) fa[i]=i;
	for(int i=1;i<=q;++i){
		scanf("%d%d",&u,&v);
		u=find(u);v=find(v+n);
		if(u!=v) fa[u]=v;
	}
	for(int i=1;i<=m;++i){
		u=find(i+n);v=find(1);
		if(u!=v){
			fa[u]=v;
			++ans;
		}
	}
	for(int i=1;i<=n;++i){
		u=find(i);v=find(1+n);
		if(u!=v){
			fa[u]=v;++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}