#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long

#define N 10000000
ll a[N];int top;

int main()
{
	//freopen("1.in","r",stdin);
	ll n,i;int k;
	scanf("%lld%d",&n,&k);
	for (i=1;i*i<n;++i)
	if(!(n%i)) {a[++top]=i;a[++top]=n/i;}
	if (i*i==n) a[++top]=i;
	if (k>top) printf("%d",-1);
	else 
	{
		nth_element(a+1,a+k,a+top+1);
		printf("%lld",a[k]);
	}
}