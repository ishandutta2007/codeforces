#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[505][505],b[505][505],c[22][505][505];

int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}

int main(){
	memset(c,20,sizeof(c));
	memset(c[0],0,sizeof(c[0]));
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				printf("-1 ");
			}puts("");
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			scanf("%d",&a[i][j]);
			c[0][i][j]=0;
		}
	}
	for(i=1;i<n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=1;i<=m;i++){
		b[0][i]=b[n][i]=100000000;
	}
	for(i=1;i<=n;i++){
		a[i][0]=a[i][m]=100000000;
	}
	
	k/=2;
	for(t=1;t<=k;t++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				c[t][i][j]=min({c[t-1][i][j-1]+a[i][j-1],c[t-1][i][j+1]+a[i][j],c[t-1][i-1][j]+b[i-1][j],c[t-1][i+1][j]+b[i][j]});
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",c[k][i][j]*2);
		}puts("");
	}
}