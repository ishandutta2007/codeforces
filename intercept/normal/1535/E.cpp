#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int m;
int sum[M],val[M],f[M][29];
int lca(int u){
	for(int i=21;i>=0;--i)if(sum[f[u][i]])u=f[u][i];
	return u;
}
int main(){
	scanf("%d%d%d",&m,&sum[0],&val[0]);
	for(int i=1,o,u,w;i<=m;++i){
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d%d",&f[i][0],&sum[i],&val[i]);
			for(int j=1;j<=21;++j)f[i][j]=f[f[i][j-1]][j-1];
		}
		else {
			scanf("%d%d",&u,&w);
			ll ans=0;
			int h=w;
			while(w){
				int fa=lca(u);
				if(sum[fa]<=w)ans+=1ll*sum[fa]*val[fa],w-=sum[fa],sum[fa]=0;
				else ans+=1ll*w*val[fa],sum[fa]-=w,w=0;
				if(u==fa)break;
			}
			
			printf("%d %lld\n",h-w,ans);
			cout.flush();
		}
	}
	return 0;
}