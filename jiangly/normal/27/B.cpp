#include<bits/stdc++.h>
const int MAXN=55;
int n;
int deg[MAXN];
std::bitset<MAXN>g[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*(n-1)/2-1;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		++deg[u];
		++deg[v];
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			if(g[i][k])
				g[i]|=g[k];
	int u=0;
	for(int i=1;i<=n;++i)
		if(deg[i]!=n-1)
			if(!u)
				u=i;
			else if(!g[i][u])
				printf("%d %d\n",u,i);
			else
				printf("%d %d\n",i,u);
	return 0;
}