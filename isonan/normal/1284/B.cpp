#include <cstdio>
#include <algorithm>

int n,mn[100001],mx[100001],cnt,buc[1000001],top;
long long ans;
bool have[100001];
int main(){
	scanf("%d",&n);
	for(int i=1,l;i<=n;i++){
		scanf("%d",&l);
		int mx=0,mn=1000000;
		for(int j=1,tem;j<=l;j++){
			scanf("%d",&tem);
			if(tem>mn)have[i]=1;
			mx=std::max(mx,tem);
			mn=std::min(mn,tem);
		}
		if(have[i])++cnt;
		else buc[mn]++,::mx[++top]=mx;
	}
	ans=2ll*cnt*(n-cnt)+1ll*cnt*cnt;
	for(int i=1;i<=1000000;i++)buc[i]+=buc[i-1];
	for(int i=1;i<=top;i++)ans+=buc[mx[i]-1];
	printf("%lld\n",ans);
}