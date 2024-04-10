#include <cstdio>

int n,k,p[200001],f[200001],g[200001];
bool vis[200001];
int main(){
	scanf("%d%d",&n,&k);
	long long ans1=0,ans2=1;
	for(int i=1,last=0;i<=n;i++){
		scanf("%d",p+i);
		vis[i]=(p[i]>=n-k+1);
		if(vis[i]){
			if(last)ans2=1ll*ans2*(i-last)%998244353;
			last=i;
		}
	}
	for(int i=n-k+1;i<=n;i++)ans1+=i;
	f[0]=g[0]=1;
	printf("%lld %d\n",ans1,ans2);
}