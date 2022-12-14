#include <stdio.h>
#define MAX 2000000
int S1[MAX+10],S2[MAX+10];
int Prime[200010],s=1;
int func(int k)
{
	int a,s=0;
	while(k)
	{
		a = k%10;
		s*=10;
		s+=a;
		k/=10;
	}
	return s;
}
bool isPrime(int k)
{
	for(int i=1;i<s && Prime[i]*Prime[i]<=k;i++)
	{
		if(k%Prime[i]==0) return false;
	}
	Prime[s++] = k;
	return true;
}
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=2;i<=MAX;i++)
	{
		if(isPrime(i)) S1[i] = S1[i-1]+1;
		else S1[i] = S1[i-1];
	}
	for(i=1;i<=MAX;i++)
	{
		if(i==func(i)) S2[i] = S2[i-1]+1;
		else S2[i] = S2[i-1];
	}
	for(i=MAX;i>=1;i--)
	{
		if(b*S1[i]<=a*S2[i])
		{
			printf("%d",i);
			return 0;
		}
	}
}