#include <cstdio>
#include <algorithm>
#define int long long

int n,a,b,ans;
signed main(){
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	b*=5;
	ans=n;
	for(int i=0;i<=n;i++){
		if(a*i>n)break;
		ans=std::min(ans,(n-a*i)%b);
	}
	printf("%I64d\n",ans);
}