#include <cstdio>
#include <algorithm>

int n,a[200001];
int main(){
	scanf("%d",&n);
	if((n&1)==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	long long tot=(1ll*n*(2*n+1)+1)>>1;
	for(int i=1;i<=n;i++)tot-=(i<<1)-1;
	for(int i=1;i<=n;i++)a[i]=(i<<1)-1,a[i+n]=(i<<1);
	for(int i=2;i<=n;i+=2)std::swap(a[i],a[i+n]);
	for(int i=1;i<=n<<1;i++)printf("%d ",a[i]);
}