// Hydro submission #61daa85453a171eeac356a4a@1641719892568
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2005,mod=1e9+7;
int d,n,a[N],f[N],ans;
vector<int> e[N];
void dfs(int x,int fa,int p){
	f[x]=1;
	for(int y:e[x]){
		if(y==fa||a[y]+d<a[p]||a[y]>a[p]||(a[y]==a[p])&&y>p)continue;
		dfs(y,x,p);
		f[x]=1ll*f[x]*(f[y]+1)%mod;
	}
}
int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	} 
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		dfs(i,0,i);
		ans=(ans+f[i])%mod;
	}
	printf("%d",ans);
}