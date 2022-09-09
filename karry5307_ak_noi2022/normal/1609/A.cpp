#include<bits/stdc++.h>
using namespace std;
int T,n;long long a[20],b[20];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);long long ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			memcpy(b,a,sizeof(a));
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				while(b[j]%2==0) b[j]/=2,b[i]*=2; 
			}long long sum=0;
			for(int j=1;j<=n;j++) sum+=b[j];
			ans=max(ans,sum);
		}printf("%lld\n",ans);
	}
	return 0;
}