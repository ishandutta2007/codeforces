#include <stdio.h>
#define MAX 1234567890

int a,c;
long long int x[510],y[510];
long long int check[3][510][510];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	x[a+1] = b;
	for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
	
	for(int t=1;t<=a;t++) check[(a+1)%2][t][c+1] = MAX;
	for(int s=a;s>=2;s--)
	{
		for(int t=1;t<s;t++)
		{
			for(int k=0;k<=c;k++)
			{
				long long int s1 = check[(s+1)%2][s][k] + (x[s+1]-x[s])*y[s];
				long long int s2 = check[(s+1)%2][t][k+1] + (x[s+1]-x[s])*y[t];
				check[s%2][t][k] = s1<s2?s1:s2;
			}
			check[s%2][t][c+1] = MAX;
		}
	}
	printf("%lld",check[0][1][0]+(x[2]-x[1])*y[1]);
}