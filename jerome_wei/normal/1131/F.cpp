#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int fa[N];
int n;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int nxt[N];
int first[N],last[N];
inline void merge(int u,int v){
	int U=find(u),V=find(v);
	int X=last[U],Y=first[V];
	fa[U]=V;first[V]=first[U];
	nxt[X]=Y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) fa[i]=i,nxt[i]=0,first[i]=last[i]=i;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		merge(u,v);
	}
	int tmp=first[find(1)];
	//cout<<tmp<<endl;
	while(tmp){
		printf("%d ",tmp);
		tmp=nxt[tmp];
	}
	return 0;
}