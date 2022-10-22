#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
int a[M];
long long p[M],s[M];
void work(){
	long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum+=a[i];
	if(sum+1ll*(n-2)*a[1]>0||sum+1ll*(n-2)*a[n]<0){
		puts("INF");
		return;
	}
	s[n+1]=0;
	long long ans=-1e18;
	for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i];
	for(int i=n;i>=1;--i)s[i]=s[i+1]+a[i];
	for(int i=1;i<n;++i){
		long long t=-a[i];
		long long S=p[i]*a[n]+s[i+1]*a[1]-1ll*a[1]*a[n]+t*a[n]*i+t*a[1]*(n-i)+t*(p[n-1]-a[1]);
		ans=max(ans,S);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}