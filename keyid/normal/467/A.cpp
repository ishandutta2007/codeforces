#include <cstdio>

int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		if (q-p>=2) cnt++;
	}
	printf("%d",cnt);
	return 0;
}