#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[100009];
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&w,&v);
		vis[w]=1;
	}
	int p;
	for(int i=1;i<=n;++i){
		if(!vis[i])p=i;
	}
	for(int i=1;i<=n;++i){
		if(p!=i)printf("%d %d\n",p,i);
		vis[i]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}