#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int T,a[30],n,m,K,f[201000],g[201000];
char s[201000];
void sol(){
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",s+1);
	memset(a,0,sizeof(a));
	for(int i=1;i<=K;++i)a[s[i]-'A'+1]++;
	for(int j=0;j<=K;++j)f[j]=g[j]=inf;
	f[0]=0;
	long long ans=(long long)1e18;
	for(int i=1;i<=26;++i){
		for(int j=0;j<=K;++j)g[j]=f[j];
		for(int j=i+1;j<=26;++j)
			for(int k=K;k>=a[j];--k)
				g[k]=min(g[k],g[k-a[j]]+a[j]);
		for(int k=K-1;k>=0;--k)g[k]=min(g[k],g[k+1]);
		for(int j=0;j<=a[i];++j){
			int lef=j,rig=a[i]-j;
			if(lef<=n&&g[n-lef]!=inf&&K-a[i]-g[n-lef]+rig>=m)
				ans=min(ans,(long long)lef*max(0,m-(K-a[i]-g[n-lef])));
		}
		for(int k=K;k>=a[i];--k)
			f[k]=min(f[k],f[k-a[i]]+a[i]);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}