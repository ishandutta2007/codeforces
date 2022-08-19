#include <cstdio>
#define int long long

long long p[100001];
long long n,m,k;
signed main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%I64d",p+i);
	int ans=0;
	for(int i=1,last=0;i<=m;){
		long long x=(p[i]-last+k-1)/k;
		while(((p[i+1]-last+k-1)/k)==x&&i<=m)++i;
		++ans;
		last=i;
		++i;
	}
	printf("%I64d\n",ans);
}