#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 101010;
const int P = 10007;
int n,i,a[N],ans;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	
	for (i=1;i<=n;i++)
	ans=(ans+1LL*a[i]*a[n-i+1]%P)%P;
	printf("%d\n",ans);
}