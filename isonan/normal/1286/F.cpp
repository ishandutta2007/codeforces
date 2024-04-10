#include <cstdio>
#include <vector> 
#include <cstring>
#include <algorithm>

int n,lim,f[1048576];
long long a[21],sum[1048576];
int main(){
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++){
		scanf("%lld",a+(cnt++));
		if(!a[cnt-1])--cnt;
	}
	n=cnt;
	int ans=0;
	for(int i=0;i<(1<<n);i++)f[i]=-n*n;
	for(int i=0;i<(1<<n);i++){
		int cnt=__builtin_popcount(i);
		int fst=0;
		for(int j=0;j<n;j++)if(i&(1<<j))fst=j;
		for(int j=i^(1<<fst);j;j=(j-1)&i)
			f[i]=std::max(f[i],f[j]+f[i^j]);
		if(f[i]<1&&(sum[i]&1)!=(cnt&1)){
			long long l=(sum[i]-cnt+1),r=(sum[i]-1+cnt);
			for(int j=(i-1)&i;j;j=(j-1)&i){
				if((sum[j]*2)>=l&&(sum[j]*2)<=r){f[i]=1;break;}
			}
		}
		ans=std::max(ans,f[i]);
		for(int j=0;j<n;j++)
			if(!(i&(1<<j)))sum[i|(1<<j)]=sum[i]+a[j],f[i|(1<<j)]=std::max(f[i],f[i|(1<<j)]);
	}
	printf("%d\n",n-ans);
}