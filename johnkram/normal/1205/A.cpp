#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 200005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,i,a[MAXN];
int main()
{
	cin>>n;
	if(!(n&1))
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=n;i++)a[i]=i*2-1;
	for(i=1;i<=n;i++)a[i+n]=i*2;
	for(i=2;i<n;i+=2)swap(a[i],a[i+n]);
	puts("YES");
	for(i=1;i<=n<<1;i++)printf("%d ",a[i]);
	return 0;
}