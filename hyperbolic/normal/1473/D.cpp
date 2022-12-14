#include <stdio.h>

char x[200010];
int left[200010],right[200010],minL[200010],maxL[200010],minR[200010],maxR[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		left[0] = 0, right[a+1] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='-') left[i] = left[i-1] -1;
			else left[i] = left[i-1] + 1;
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='-') right[i] = right[i+1] - 1;
			else right[i] = right[i+1] + 1;
		}
		
		minL[0] = maxL[0] = minR[a+1] = maxR[a+1] = 0;
		for(int i=1;i<=a;i++) minL[i] = minL[i-1]<left[i]?minL[i-1]:left[i];
		for(int i=1;i<=a;i++) maxL[i] = maxL[i-1]>left[i]?maxL[i-1]:left[i];
		for(int i=a;i>=1;i--) minR[i] = minR[i+1]<right[i]?minR[i+1]:right[i];
		for(int i=a;i>=1;i--) maxR[i] = maxR[i+1]>right[i]?maxR[i+1]:right[i];
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			
			int s = minL[c-1] < left[c-1]+right[d+1]-maxR[d+1]?minL[c-1] : left[c-1]+right[d+1]-maxR[d+1];
			int t = maxL[c-1] > left[c-1]+right[d+1]-minR[d+1]?maxL[c-1] : left[c-1]+right[d+1]-minR[d+1];
			//printf("%d %d!!\n",s,t);
			printf("%d\n",t-s+1);
		}
	}
}