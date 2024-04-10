#include <cstdio>
#include <algorithm>

long long a[200001];
long long st[200001][21];
int n,t;
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",a+i);
		int ans=1;
		for(int i=n;i>1;--i){
			a[i]-=a[i-1];
			if(a[i]<0)a[i]=-a[i];
		}
		for(int i=2;i<=n;++i)st[i][0]=a[i];
		for(int j=1;(1<<j)<=n-1;++j)
			for(int i=2;i+(1<<j)-1<=n;++i)
				st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for(int i=2;i<=n;++i){
			long long val=0;
			int now=i;
			for(int j=20;~j;--j)
				if(now+(1<<j)-1<=n){
					long long x=gcd(st[now][j],val);
					if(x!=1)val=x,now+=1<<j;
				}
			ans=std::max(ans,now-i+1);
		}
		printf("%d\n",ans);
	}
}