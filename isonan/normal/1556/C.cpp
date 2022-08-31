#include <cstdio>
#include <algorithm>
#define int long long

int n,c[1001];
long long S[1001];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",c+i),S[i]=S[i-1]+((i&1)?c[i]:(-c[i]));
	long long ans=0;
	for(int i=1;i<=n;++i){
		long long sum=0,mn=0;
		for(int j=i+1;j<=n;++j){
			if(i%2==0)continue;
			long long L=std::max(std::max(1ll,1ll-sum),-mn),R=std::min(c[i],c[j]-sum);
			if(L<=R&&j%2==0)ans+=R-L+1;
			// printf("%d %d %d %d\n",i,j,L,R);
			sum+=(j%2==0)?-c[j]:c[j];
			mn=std::min(mn,sum);
		}
	}
	printf("%lld\n",ans);
}