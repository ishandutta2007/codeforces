#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,m1,m2;
int fa[M],fb[M];
set<int>s[2];
int find(int x,int *f){
	return f[x]==x?x:f[x]=find(f[x],f);
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;++i)fa[i]=fb[i]=i;;
	for(int i=1,u,v;i<=m1;++i){
		scanf("%d%d",&u,&v);
		fa[find(u,fa)]=find(v,fa);
	}
	for(int i=1,u,v;i<=m2;++i){
		scanf("%d%d",&u,&v);
		fb[find(u,fb)]=find(v,fb);
	}
	printf("%d\n",n-1-max(m1,m2));
	for(int i=2;i<=n;++i){
		if(find(i,fa)!=find(1,fa)&&find(i,fb)!=find(1,fb)){
			fa[find(i,fa)]=find(1,fa);
			fb[find(i,fb)]=find(1,fb);
			printf("1 %d\n",i);
		}
	}
	for(int i=2;i<=n;++i){
		if(find(i,fa)!=find(1,fa))s[0].insert(find(i,fa));
		if(find(i,fb)!=find(1,fb))s[1].insert(find(i,fb));
	}
	if(s[0].size()>s[1].size())swap(s[0],s[1]);
	for(auto it0=s[0].begin(),it1=s[1].begin();it0!=s[0].end();++it0,++it1){
		printf("%d %d\n",*it0,*it1);
	}
	return 0;
}