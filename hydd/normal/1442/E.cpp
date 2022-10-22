#include<bits/stdc++.h>
using namespace std;
int T,n,col[210000],pos,res;
int edgenum,vet[410000],Next[410000],Head[210000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u,int fa,int lst,int tot){
	if (tot>res){
		res=tot;
		pos=u;
	}
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa) dfs(vet[e],u,col[vet[e]]?col[vet[e]]:lst,tot+(col[vet[e]]==3-lst));
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		pos=0; res=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&col[i]);
			if (col[i]) pos=i;
		}
		edgenum=0;
		for (int i=1;i<=n;i++) Head[i]=0;
		int u,v;
		for (int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		if (!pos){
			puts("1");
			continue;
		}
		dfs(pos,0,col[pos],1); dfs(pos,0,col[pos],1);
		printf("%d\n",res/2+1);
	}
	return 0;
}