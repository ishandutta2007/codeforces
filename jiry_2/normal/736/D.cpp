#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
bitset<4100>b[2100];
int n,m,u[510000],v[510000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); b[k1][k2]=1;
		u[i]=k1; v[i]=k2;
	}
	for (int i=1;i<=n;i++) b[i][i+n]=1;
	for (int i=1;i<=n;i++){
		int where=i;
		for (int j=i+1;j<=n;j++) if (b[j][i]) where=j;
		swap(b[i],b[where]);
		for (int j=1;j<=n;j++)
			if (b[j][i]&&j!=i) b[j]^=b[i];
	}
	for (int i=1;i<=m;i++) if (b[v[i]][u[i]+n]==0) printf("YES\n"); else printf("NO\n");
//	printf("%d\n",ans);
	return 0;
}