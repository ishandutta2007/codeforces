#include <stdio.h>

int x[200010];
int check[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[a+1] = 0;
		
		int ans1 = 0, ans2 = a, ans3 = 0;
		int control1 = 0, control2 = 0;
		check[0] = check[1] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]>0)
			{
				if(control2<=1 && check[control2]==0)
				{
					check[control2] = 1;
					int C1 = 0, C2 = 0;
					for(int j=i;j<=a;j++)
					{
						if(x[j]==2) C1++;
						else if(x[j]==1);
						else if(x[j]==0) break;
						else if(x[j]==-1) C2 = 1-C2;
						else if(x[j]==-2) C1++, C2 = 1-C2;
						if(C1>ans1 && C2==0)
						{
							ans1 = C1;
							ans2 = i-1, ans3 = a-j;
						}
					}
				}
			}
			else if(x[i]<0)
			{
				if(control2<=1)
				{
					control2++;
					int C1 = 0, C2 = 0;
					for(int j=i;j<=a;j++)
					{
						if(x[j]==2) C1++;
						else if(x[j]==1);
						else if(x[j]==0) break;
						else if(x[j]==-1) C2 = 1-C2;
						else if(x[j]==-2) C1++, C2 = 1-C2;
						if(C1>ans1 && C2==0)
						{
							ans1 = C1;
							ans2 = i-1, ans3 = a-j;
						}
					}
				}
			}
			else
			{
				control2 = 0;
				check[0] = check[1] = 0;
			}
		}
		printf("%d %d\n",ans2,ans3);
	}
}