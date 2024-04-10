#include <cstdio>
#include <algorithm>

long long n,b[200001],a[200001];
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",b+i);
	for(long long i=1,x=0;i<=n;i++){
		a[i]=x+b[i];
		x=std::max(x,a[i]);
		printf("%lld ",a[i]);
	}
}