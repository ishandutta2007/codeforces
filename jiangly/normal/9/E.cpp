#include<bits/stdc++.h>
const int MAXN=50;
int n,m;
int fa[MAXN+5],deg[MAXN+5];
bool exist_cycle;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool check1(){
	for(int i=1;i<=n;++i)
		if(deg[i]!=2)
			return 0;
	for(int i=2;i<=n;++i)
		if(find(i)!=find(1))
			return 0;
	return 1;
}
bool check2(){
	if(m>=n)
		return 0;
	if(exist_cycle)
		return 0;
	for(int i=1;i<=n;++i)
		if(deg[i]>2)
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++deg[u];
		++deg[v];
		exist_cycle|=find(u)==find(v);
		fa[fa[u]]=fa[v];
	}
	if(check1()){
		puts("YES");
		puts("0");
		return 0;
	}
	if(!check2()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",n-m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(deg[i]<2&&deg[j]<2&&find(i)!=find(j)){
				fa[fa[i]]=fa[j];
				++deg[i];
				++deg[j];
				printf("%d %d\n",i,j);
			}
	int u,v;
	for(int i=1;i<=n;++i)
		if(deg[i]<2){
			u=i;
			break;
		}
	for(int i=n;i;--i)
		if(deg[i]<2){
			v=i;
			break;
		}
	printf("%d %d\n",u,v);
	return 0;
}