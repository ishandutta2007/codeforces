#include <cstdio>

int t,n,k,s[100001],a[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&k);
		for(int i=n-k+1;i<=n;++i)scanf("%d",s+i);
		for(int i=n-k+2;i<=n;++i)a[i]=s[i]-s[i-1];
		bool ok=1;
		for(int i=n-k+3;i<=n;++i)
			if(a[i]<a[i-1])ok=0;
		long long sum=s[n-k+1];
		if(n-k+2<=n&&sum>1ll*a[n-k+2]*(n-k+1))ok=0;
		if(ok)puts("Yes");
		else puts("No");
	}
}