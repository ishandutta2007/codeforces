// Hydro submission #61cc62becb38e9d32635735d@1640784574985
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int dep[N],maxdep[N],n,k,leaf,tot,a[N];
vector<int> e[N];
void dfs(int x,int fa){
	for(int y:e[x]){
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		maxdep[x]=max(maxdep[x],maxdep[y]);
	}
	maxdep[x]=max(maxdep[x],dep[x]);
}
void dfs1(int x,int s){
	int son=0;
	if(x!=1&&e[x].size()==1)a[++tot]=s;
	for(int y:e[x]){
		if(dep[y]!=dep[x]+1)continue;
		if(maxdep[y]>maxdep[son])son=y;
	}
	if(!son)return;
	dfs1(son,s+1);
	for(int y:e[x]){
		if(dep[y]!=dep[x]+1||y==son)continue;
		dfs1(y,1);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y),e[y].push_back(x);
	}
	for(int i=2;i<=n;i++)if(e[i].size()==1)leaf++;
	if(leaf<=k){
		if(k>n/2&&leaf<=n/2)k=n/2;
		else if(leaf>n/2)k=leaf;
		printf("%lld",1ll*(n-k)*k);
		return 0;
	}
	dfs(1,0);
	dfs1(1,1);
	sort(a+1,a+tot+1);
	int sum=0;
	for(int i=tot;i>=tot-k+1;i--)sum+=a[i];
	sum=n-sum;
	if(sum>n/2)sum=n/2;
	printf("%lld",1ll*(n-k-sum)*(k-sum)); 
}