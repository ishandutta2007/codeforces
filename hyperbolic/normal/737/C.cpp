#include <stdio.h>

int count[200010],sum[200010],sum2[200010];
int main()
{
	int a,b;
	int save = 0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(i==b)
		{
			if(c!=0) save++;
			count[0]++;
		}
		else count[c]++;
	}
	
	for(int i=0;i<=a;i++) if(count[i]==0) sum2[i] = 1;
	for(int i=1;i<=a;i++) sum2[i] += sum2[i-1];
	
	for(int i=a;i>=0;i--) sum[i] = count[i];
	for(int i=a;i>=0;i--) sum[i] += sum[i+1];
	
	int ans = a;
	int p = a;
	while(count[p]==0) p--;
	
	while(p>=0)
	{
		int S = sum[p+1];
		if(count[0]>=2) S += (count[0]-1);
		
		int t = S>sum2[p]?S:sum2[p];
		ans = ans<t?ans:t;
		
		p--;
		while(p>=0&&count[p]==0) p--;
	}
	printf("%d",ans+save);
}