#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[8010],sum[8010];
bool can[8010];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			can[i]=0;
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(sum[j]-sum[i-1]<=n) can[sum[j]-sum[i-1]]=true;
		for(int i=1;i<=n;i++) if(can[a[i]]) ans++;
		printf("%d\n",ans);
	}
}