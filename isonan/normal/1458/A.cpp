#include <cstdio>

int n,m;
long long a[200001],b[200001];
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	long long g=0;
	long long mn=a[1];
	int p=1;
	for(int i=2;i<=n;i++)if(mn>a[i])mn=a[i],p=i;
	for(int i=1;i<=n;i++)if(p!=i)g=gcd(g,a[i]-a[p]);
	for(int i=1;i<=m;i++)printf("%lld ",gcd(g,a[p]+b[i]));
}