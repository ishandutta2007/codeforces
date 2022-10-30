#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,vis[400500],a[400500],b[400500],c[400500];
ll res;

void dfs(int x){
	//printf("%d\n",x);
	if(vis[x]){return;}
	vis[x]=1;
	dfs(a[x]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		res=1;
		scanf("%d",&n);
		memset(vis,0,n*4+50);
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		for(i=1;i<=n;i++){
			a[b[i]]=c[i];
		}
		for(i=1;i<=n;i++){
			if(vis[i]){continue;}
			res=res*2%M;
			dfs(i);
		}
		printf("%lld\n",res);
	}
}