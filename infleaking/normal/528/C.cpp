#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],ne[N],la[N],t=1,ban[N];
int deg[N];
int ans[N],a1,n,m;
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	deg[x]++;
}
void dfs(int x){
	for (int y=la[x];y;y=la[x]){
		la[x]=ne[y];
		if (ban[y])continue;
		ban[y]=ban[y^1]=1;
		dfs(w[y]);
	}
	ans[++a1]=x;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	int las=0;
	for (int i=1;i<=n;i++){
		if (deg[i]&1){
			if (las){
				link(las,i);
				link(i,las);
				las=0;
			}else las=i;
		}
	}
	if (las)link(las,las),link(las,las);
	if ((t/2)&1)link(1,1),link(1,1);
	dfs(1);
	cout<<t/2<<endl;
	for (int i=1;i<a1;i++){
		if (i&1)printf("%d %d\n",ans[i],ans[i+1]);
		else printf("%d %d\n",ans[i+1],ans[i]);
	}
}