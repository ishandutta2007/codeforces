#include <stdio.h>
int min(int a, int b, int c, int d)
{
	int m = a;
	m=m<b?m:b;
	m=m<c?m:c;
	m=m<d?m:d;
	return m;
}
int max(int a, int b, int c, int d)
{
	int m = a;
	m=m>b?m:b;
	m=m>c?m:c;
	m=m>d?m:d;
	return m;
}
int main()
{
	int n;
	long long int ans = 0;
	int a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	for(int i=1;i<=n;i++)
	{
		int s1 = a+b+i;
		int s2 = a+c+i;
		int s3 = b+d+i;
		int s4 = d+c+i;
		
		int m = min(s1,s2,s3,s4);
		int M = max(s1,s2,s3,s4);
		if(m+n<M+1) continue;
		ans+=(m+n)-(M+1)+1;
	}
	printf("%I64d",ans);
}