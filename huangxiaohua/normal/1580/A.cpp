#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[666][666],b[666][666],res,f[666][666],sb,x[666][666],y[666][666];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(f,1,sizeof(f));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%1d",&a[i][j]);
				b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
				x[i][j]=x[i-1][j]+a[i][j];
				y[i][j]=y[i][j-1]+a[i][j];
			}
		}
		
		res=1145141919;
		for(i=5;i<=n;i++){
			for(j=1;j<=m;j++){
				for(k=j+3;k<=m;k++){
					sb=b[i-1][k-1]-b[i-4][k-1]-b[i-1][j]+b[i-4][j];
					sb+=(k-j-1)-(y[i-4][k-1]-y[i-4][j]);
					sb+=3-(x[i-1][k]-x[i-4][k]);
					sb+=3-(x[i-1][j]-x[i-4][j]);
					
					f[j][k]=min(f[j][k]+(y[i-1][k-1]-y[i-1][j])+!a[i-1][j]+!a[i-1][k],sb);
					res=min(res,f[j][k]+(k-j-1)-(y[i][k-1]-y[i][j]));
				}
			}
			
		}
		
		printf("%d\n",res);
	}
}