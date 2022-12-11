#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
int a[200010];
long long sum[200010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+((i&1)?-a[i]:a[i]),ans+=(i&1)?a[i]:0;
		long long mn[2]={1000000000000000000ll,1000000000000000000ll},tmp=-1000000000000000000ll;
		for(int i=0;i<=n;i++){
			tmp=max(tmp,sum[i]-mn[i&1]);
			mn[i&1]=min(mn[i&1],sum[i]);
		}
		printf("%lld\n",ans+max(tmp,0ll));
	}
}