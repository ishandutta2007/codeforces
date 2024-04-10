#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
map<ll,int> s;
int n,i,j,k,a[MAXN];
ll b[MAXN];
int main()
{
	scanf("%d",&n);
	n/=2;
	for(i=1;i<MAXN;i++)s[(ll)i*i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]%4==2)
		{
			puts("No");
			return 0;
		}
		for(j=k+1;j<MAXN;j++)if(s.count((ll)j*j+a[i]))break;
		if(j==MAXN)
		{
			puts("No");
			return 0;
		}
		b[i*2-1]=(ll)j*j-(ll)k*k;
		b[i*2]=a[i];
		k=s[(ll)j*j+a[i]];
	}
	puts("Yes");
	for(i=1;i<=n<<1;i++)cout<<b[i]<<' ';
	return 0;
}