#include <stdio.h>
#define MAX 123456789
#define MIN -123456789
int x[1010][1010],left[1010][1010],right[1010][1010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		left[1][1] = right[1][1] = x[1][1];
		for(int k=3;k<=a+b;k++)
		{
			for(int i=1;i<k;i++)
			{
				int j = k-i;
				if(1<=i&&i<=a&&1<=j&&j<=b)
				{
					int s,t;
					int L = MAX, R = MIN;
					s = i, t = j-1;
					if(1<=s&&s<=a&&1<=t&&t<=b)
					{
						L = L<left[s][t]?L:left[s][t];
						R = R>right[s][t]?R:right[s][t];
					}
					s = i-1, t = j;
					if(1<=s&&s<=a&&1<=t&&t<=b)
					{
						L = L<left[s][t]?L:left[s][t];
						R = R>right[s][t]?R:right[s][t];
					}
					left[i][j] = L + x[i][j];
					right[i][j] = R + x[i][j];
				}
			}
		}
		if(left[a][b]<=0&&0<=right[a][b]&&(a+b)%2==1) printf("YES\n");
		else printf("NO\n");
	}
}