#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[110000],b[110000],c[110000]; bool vis[110000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) vis[i]=false;
		for (int i=1;i<=m;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			vis[b[i]]=true;
		}
		int u=0;
		for (int i=1;i<=n;i++)
			if (!vis[i]) u=i;
		for (int i=1;i<=n;i++)
			if (u!=i) printf("%d %d\n",i,u);
	}
	return 0;
}