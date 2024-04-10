#include <stdio.h>
#define SIZE 512

int x[300010],y[300010];
long long int max[610];

struct str{
	long long int first;
	long long int second;
	long long int sum;
}value[610][610],z[1210];


int main()
{
	int a;
	scanf("%d",&a);
	int b = (1<<a);
	for(int i=0;i<b;i++) scanf("%d",&x[i]);
	for(int i=b;i<SIZE;i++) x[i] = 0;
	b = b>SIZE?b:SIZE;
	
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<b;j++) y[j] = x[j^i];
		
		for(int start=0;start<b;start+=SIZE)
		{
			long long int val,S;
			
			val = 0, S = 0;
			for(int j=start;j<start+SIZE;j++)
			{
				S = S+y[j]>y[j]?S+y[j]:y[j];
				val = val>S?val:S;
			}
			max[i] = max[i]>val?max[i]:val;
			
			val = 0, S = 0;
			for(int j=start;j<start+SIZE;j++)
			{
				S += y[j];
				val = val>S?val:S;
			}
			value[start/SIZE][i].first = val; // left
			
			val = 0, S = 0;
			for(int j=start+SIZE-1;j>=start;j--)
			{
				S += y[j];
				val = val>S?val:S;
			}
			value[start/SIZE][i].second = val; // right
			
			S = 0;
			for(int j=start;j<start+SIZE;j++) S += y[j];
			value[start/SIZE][i].sum = S;
		}
	}
	
	int bit = 0;
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int d;
		scanf("%d",&d);
		bit ^= (1<<d);
		
		int bit3 = bit%SIZE, bit2 = bit/SIZE;
			
		for(int i=0;i<=2*SIZE;i++) z[i]={0,0,0};
		for(int i=0;i<SIZE;i++) z[i+SIZE] = value[i^bit2][bit3];
		long long int ans = max[bit3];
		for(int i=SIZE-1;i>=1;i--)
		{
			long long int val;
			val = z[2*i].second + z[2*i+1].first;
			ans = ans>val?ans:val;
			val = z[2*i].first > z[2*i].sum + z[2*i+1].first? z[2*i].first : z[2*i].sum + z[2*i+1].first;
			z[i].first = val;
			val = z[2*i+1].second > z[2*i+1].sum + z[2*i].second? z[2*i+1].second : z[2*i+1].sum + z[2*i].second;
			z[i].second = val;
			z[i].sum = z[2*i].sum + z[2*i+1].sum;
		}
		printf("%lld\n",ans);
	}
}