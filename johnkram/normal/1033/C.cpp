#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
bool ans[MAXN];
int n,i,j,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;ans[i++]=1)b[a[i]]=i;
	for(i=n;i;i--)
	{
		for(j=(b[i]-1)%i+1;j<=n;j+=i)if(a[j]>i)ans[b[i]]&=ans[j];
		ans[b[i]]^=1;
	}
	for(i=1;i<=n;i++)if(ans[i])putchar('A');
	else putchar('B');
	return 0;
}