#include <stdio.h>
#define MAX 1234567890

int a;
int x[3][200010];
int max1[3][200010],max2[3][200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=2;i++) for(int j=1;j<=a;j++) x[i][j]++;
		x[1][1] = 0;
		
		for(int i=1;i<=a;i++) max1[1][i] = x[1][i] + (2*a-i+1);
		for(int i=a-1;i>=1;i--) max1[1][i] = max1[1][i]>max1[1][i+1]?max1[1][i]:max1[1][i+1];
		for(int i=1;i<=a;i++) max1[2][i] = x[2][i] + i;
		for(int i=a-1;i>=1;i--) max1[2][i] = max1[2][i]>max1[2][i+1]?max1[2][i]:max1[2][i+1];
		for(int i=1;i<=a;i++) max2[1][i] = x[1][i] + i;
		for(int i=a-1;i>=1;i--) max2[1][i] = max2[1][i]>max2[1][i+1]?max2[1][i]:max2[1][i+1];
		for(int i=1;i<=a;i++) max2[2][i] = x[2][i] + (2*a-i+1);
		for(int i=a-1;i>=1;i--) max2[2][i] = max2[2][i]>max2[2][i+1]?max2[2][i]:max2[2][i+1];
		max1[1][a+1] = max1[2][a+1] = max2[1][a+1] = max2[2][a+1] = 0;
		
		int C = 0;
		int min = MAX;
		for(int i=1;i<=a;i++)
		{
			if(i%2==1)
			{
				int val1, val2, val3, val;
				C = C>x[1][i]?C:x[1][i];
				val1 = max1[1][i+1] - i;
				val2 = max1[2][i+1] - i;
				val3 = x[2][i];
				val = C+(2*a-2*i+1);
				val = val>val1?val:val1;
				val = val>val2?val:val2;
				val = val>val3?val:val3;
				min = min<val?min:val;
				C++;
				
				C = C>x[2][i]?C:x[2][i];
				val1 = max2[1][i+1] - i -1;
				val2 = max2[2][i+1] - i -1;
				val = C+(2*a-2*i);
				val = val>val1?val:val1;
				val = val>val2?val:val2;
				min = min<val?min:val;
				C++;
			}
			else
			{
				int val1, val2, val3, val;
				C = C>x[2][i]?C:x[2][i];
				val1 = max2[1][i+1] - i;
				val2 = max2[2][i+1] - i;
				val3 = x[1][i];
				val = C+(2*a-2*i+1);
				val = val>val1?val:val1;
				val = val>val2?val:val2;
				val = val>val3?val:val3;
				min = min<val?min:val;
				C++;
				
				C = C>x[1][i]?C:x[1][i];
				val1 = max1[1][i+1] - i -1;
				val2 = max1[2][i+1] - i -1;
				val = C+(2*a-2*i);
				val = val>val1?val:val1;
				val = val>val2?val:val2;
				min = min<val?min:val;
				C++;
			}
		}
		printf("%d\n",min);
	}
}