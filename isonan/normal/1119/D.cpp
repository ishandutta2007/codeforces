#include <cstdio>
#include <algorithm>

long long s[100001],n,t[100001],q,l,r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",s+i);
	std::sort(s+1,s+n+1);
	for(int i=1;i<n;i++)t[i]=s[i+1]-s[i];
	t[n]=1000000000000000001ll;
	std::sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+t[i];
	scanf("%I64d",&q);
	for(int i=1;i<=q;i++){
		scanf("%I64d%I64d",&l,&r);
		int lim=std::upper_bound(t+1,t+n+1,r-l+1)-t-1;
		printf("%I64d ",s[lim]+(r-l+1)*(n-lim));
	}
}