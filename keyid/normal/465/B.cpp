#include <cstdio>
int main()
{
	int a[1001]={0},n,ans=-1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	  if (a[i]==1)
	  {
	  	if (a[i-1]==1) ans++;
	  	else ans+=2;
	  }
	if (ans==-1) ans=0;
	printf("%d",ans);
	return 0;
}