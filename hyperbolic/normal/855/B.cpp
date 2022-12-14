#include <stdio.h>
long long int maxL[100010],minL[100010];
long long int maxR[100010],minR[100010];
int x[100010];
int main()
{
	int a,p,q,r;
	scanf("%d%d%d%d",&a,&p,&q,&r);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	maxL[1] = minL[1] = x[1];
	for(int i=2;i<=a;i++)
	{
		maxL[i] = maxL[i-1]>x[i]?maxL[i-1]:x[i];
		minL[i] = minL[i-1]<x[i]?minL[i-1]:x[i];
	}
	maxR[a] = minR[a] = x[a];
	for(int i=a-1;i>=1;i--)
	{
		maxR[i] = maxR[i+1]>x[i]?maxR[i+1]:x[i];
		minR[i] = minR[i+1]<x[i]?minR[i+1]:x[i];
	}
	
	long long int ans = ((long long int)p+q+r)*x[1];
	for(int i=1;i<=a;i++)
	{
		long long int s1 = p*minL[i]+r*minR[i];
		long long int s2 = p*maxL[i]+r*minR[i];
		long long int s3 = p*minL[i]+r*maxR[i];
		long long int s4 = p*maxL[i]+r*maxR[i];
		long long int s = s1;
		s = s>s2? s:s2;
		s = s>s3? s:s3;
		s = s>s4? s:s4;
		ans = ans>s+(long long int)q*x[i]?ans:s+(long long int)q*x[i];
	}
	printf("%I64d",ans);
}