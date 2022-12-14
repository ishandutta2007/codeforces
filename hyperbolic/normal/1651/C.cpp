#include <stdio.h>
#include <algorithm>
#define MAX 2e9

long long int abs(long long int k)
{
	return k>0?k:-k;
}

long long int min1[200010],min2[200010];
long long int s[110];
int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		min1[1] = min1[a] = min2[1] = min2[a] = MAX;
		for(int i=1;i<=a;i++) min1[1] = min1[1]<abs(x[1]-y[i])?min1[1]:abs(x[1]-y[i]);
		for(int i=1;i<=a;i++) min1[a] = min1[a]<abs(x[a]-y[i])?min1[a]:abs(x[a]-y[i]);
		for(int i=1;i<=a;i++) min2[1] = min2[1]<abs(x[i]-y[1])?min2[1]:abs(x[i]-y[1]);
		for(int i=1;i<=a;i++) min2[a] = min2[a]<abs(x[i]-y[a])?min2[a]:abs(x[i]-y[a]);
	
		s[1] = abs(x[1]-y[1]) + abs(x[a]-y[a]);
		s[2] = abs(x[1]-y[a]) + abs(x[a]-y[1]);
		s[3] = abs(x[1]-y[1]) + min1[a] + min2[a];
		s[4] = abs(x[1]-y[a]) + min1[a] + min2[1];
		s[5] = abs(x[a]-y[1]) + min1[1] + min2[a];
		s[6] = abs(x[a]-y[a]) + min1[1] + min2[1];
		s[7] = min1[1] + min1[a] + min2[1] + min2[a];
		std::sort(s+1,s+8);
		printf("%lld\n",s[1]);
		
		
	}
}