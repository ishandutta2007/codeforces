#include <stdio.h>

int x[300010],y[300010];
long long int DPt[300010],DPf[300010];

long long int MAX = 1;
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	DPt[0] = DPf[0] = 0;
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0) DPt[i] = MAX;
		else if(y[i]==0)
		{
			long long int ans1 = MAX, ans2 = MAX;
			if(DPt[i-1]!=MAX) ans1 = DPt[i-1]+x[i];
			if(DPf[i-1]!=MAX) ans2 = x[i];
			DPt[i] = ans1<ans2?ans1:ans2;
		}
		else
		{
			long long int ans1 = MAX, ans2 = MAX;
			if(DPt[i-1]!=MAX)
			{
				int min = 1, max = b<x[i]?b:x[i];
				while(min<=max)
				{
					int h = (min+max)/2;
					long long int t0 = x[i]-h;
					long long int f0 = y[i]-1;
					if(t0+DPt[i-1]<=b*f0+b && f0+1<=b*t0+b)
					{
						ans1 = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
			
			if(DPf[i-1]!=MAX)
			{
				int min = 1, max = b<x[i]?b:x[i];
				while(min<=max)
				{
					int h = (min+max)/2;
					long long int t0 = x[i]-h;
					long long int f0 = y[i]-1;
					if(t0<=b*f0+b && f0+DPf[i-1]+1<=b*t0+b)
					{
						ans2 = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
			DPt[i] = ans1<ans2?ans1:ans2;
		}
		
		if(y[i]==0) DPf[i] = MAX;
		else if(x[i]==0)
		{
			long long int ans1 = MAX, ans2 = MAX;
			if(DPf[i-1]!=MAX) ans1 = DPf[i-1]+y[i];
			if(DPt[i-1]!=MAX) ans2 = y[i];
			DPf[i] = ans1<ans2?ans1:ans2;
		}
		else
		{
			long long int ans1 = MAX, ans2 = MAX;
			if(DPt[i-1]!=MAX)
			{
				int min = 1, max = b<y[i]?b:y[i];
				while(min<=max)
				{
					int h = (min+max)/2;
					long long int t0 = x[i]-1;
					long long int f0 = y[i]-h;
					if(t0+DPt[i-1]+1<=b*f0+b && f0<=b*t0+b)
					{
						ans1 = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
			
			if(DPf[i-1]!=MAX)
			{
				int min = 1, max = b<y[i]?b:y[i];
				while(min<=max)
				{
					int h = (min+max)/2;
					long long int t0 = x[i]-1;
					long long int f0 = y[i]-h;
					if(t0+1<=b*f0+b && f0+DPf[i-1]<=b*t0+b)
					{
						ans2 = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
			DPf[i] = ans1<ans2?ans1:ans2;
		}
	}
	
	if(DPt[a]==MAX&&DPf[a]==MAX) printf("NO");
	else printf("YES");
}