#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[3050],f[3050][3050],pre[3050][3050],f2[3050][3050],res;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			memset(f[i],1,sizeof(f[i]));
			memset(pre[i],1,sizeof(pre[i]));
			memset(f2[i],0,sizeof(f2[i]));
		}
		memset(f[n],0,sizeof(f[n]));
		memset(pre[n],0,sizeof(pre[n]));
		res=f[1][1];
		for(i=n-1;i>=1;i--){
			for(j=i;j>=1;j--){
				f2[j][i]=f2[j+1][i];
				if(j+a[j]>i){f2[j][i]++;}
			}
			for(j=i+1;j<=i+a[i];j++){
				f[i][j]=f2[i+1][j-1]+pre[j][i+a[i]+1];
			}
			for(j=n;j>=i;j--){
				pre[i][j]=min(pre[i][j+1],f[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			res=min(res,f[1][i]);
		}
		printf("%d\n",res);
	}
}