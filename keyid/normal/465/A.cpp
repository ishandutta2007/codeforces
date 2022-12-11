#include <cstdio>
int main()
{
	char a[101];
	int n,ans=0,m=0;
	scanf("%d%s",&n,a);
	for (int i=0;i<n;i++) a[i]-=48;
	a[0]+=1;
	while (a[m]>1&&m<n)
	{
		a[++m]++;
		ans++;
	}
	if (m<n) ans++;
	printf("%d",ans);
	return 0;
}