#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,t,x,y,n,m,vis[1005000],b[1005000];
ll a[1005000],sum0,sum1;
vector<int> v[1005000];

void dfs(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(vis[i]){continue;}
		b[i]=b[x]^1;
		dfs(i);
	}
}

void dfs2(int x){
	vis[x]=1;
	if(b[x]){sum1+=a[x];}
	else{sum0+=a[x];}
	for(auto i:v[x]){
		if(b[i]==b[x]){k=1;}
		if(vis[i]){continue;}
		dfs2(i);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			v[i].clear();
			scanf("%lld",&a[i]);
			vis[i]=b[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[i]=k-a[i];
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		memset(vis,0,n*4+50);
		k=sum0=sum1=0;
		dfs2(1);
		if(k){
			if((sum0+sum1)%2==0){puts("YES");goto aaa;}
		}
		else{
			if(sum0==sum1){puts("YES");goto aaa;}
		}
		puts("NO");
		aaa:;
	}
}