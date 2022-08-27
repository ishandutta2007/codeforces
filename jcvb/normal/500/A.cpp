#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int go[100005];
int qu[100005],p,q;
int vis[100005]={0};
void bfs(int rt){
	p=q=0;
	qu[q++]=rt;vis[rt]=1;
	while(p!=q){
		int u=qu[p++];
		if(!vis[go[u]]){
			vis[go[u]]=1;
			qu[q++]=go[u];
		}
	}
}

int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n-1;i++){
		int v;
		scanf("%d",&v);
		go[i]=i+v;
	}
	go[n]=0;vis[0]=1;
	bfs(1);
	if(vis[t]==1)printf("YES\n");
	else printf("NO\n");
	return 0;


}