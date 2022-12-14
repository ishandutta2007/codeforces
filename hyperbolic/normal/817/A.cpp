#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int x = abs(a-c);
	int y = abs(b-d);
	if(x%e==0&&y%f==0)
	{
		int s = x/e;
		int t = y/f;
		if((s+t)%2==0) printf("YES");
		else printf("NO");
	}
	else printf("NO");
}