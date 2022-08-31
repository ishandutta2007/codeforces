#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define MAXN 100005
using namespace std;
int n;
struct edge{int v,next;}e[MAXN];int etot=0,g[MAXN>>1];
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int ans[MAXN];int len=0;

void dfs(int u){
	for (;~g[u];){
        int t=g[u];g[u]=e[g[u]].next;
		dfs(e[t].v);
		ans[len++]=t;
	}
}
int main()
{
	memset(g,-1,sizeof(g));
	scanf("%d",&n);
	if(n&1){
		printf("-1\n");
		return 0;
	}
	for (int i=0;i<n;i++)ae(i/2,i%(n>>1));
	dfs(0);
	for (int i=0;i<n;i++)if(ans[i]==0){
		for (int j=n;j>=0;j--){
			if(j<n)printf(" ");
			printf("%d",ans[(i+j)%n]);
		}
		printf("\n");
		return 0;
	}
}