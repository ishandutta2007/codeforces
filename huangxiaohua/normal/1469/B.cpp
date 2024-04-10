#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,a[105],b[105],c[105],d[105],res=0,t,m;

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		res=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[i]=c[i-1]+a[i];
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);
			d[i]=d[i-1]+b[i];
		}
		/*for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				dp[i][j]=-1000000;
			}
		}*/
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				res=max(res,c[i]+d[j]);
			}
		}
		printf("%d\n",res);
	}
}