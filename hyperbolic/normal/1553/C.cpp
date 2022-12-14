#include <stdio.h>

char x[110];
int y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans1 = 10, ans2 = 10;
		int s1, s2;
		scanf("%s",x+1);
		for(int i=1;i<=10;i++)
		{
			if(x[i]=='1') y[i] = 1;
			if(x[i]=='0') y[i] = 0;
			if(x[i]=='?')
			{
				if(i%2==0) y[i] = 1;
				else y[i] = 0;
			}
		}
		
		s1 = 0, s2 = 0;
		for(int i=1;i<=10;i++)
		{
			if(i%2==1)
			{
				s1 += y[i];
				if(s2+(11-i)/2 < s1 || s1 + (9-i)/2 < s2)
				{
					ans1 = i;
					break;
				}
			}
			else
			{
				s2 += y[i];
				if(s2+(10-i)/2<s1 || s1+(10-i)/2 < s2)
				{
					ans1 = i;
					break;
				}
			}
		}
		
		for(int i=1;i<=10;i++)
		{
			if(x[i]=='1') y[i] = 1;
			if(x[i]=='0') y[i] = 0;
			if(x[i]=='?')
			{
				if(i%2==0) y[i] = 0;
				else y[i] = 1;
			}
		}
		
		s1 = 0, s2 = 0;
		for(int i=1;i<=10;i++)
		{
			if(i%2==1)
			{
				s1 += y[i];
				if(s2+(11-i)/2 < s1 || s1 + (9-i)/2 < s2)
				{
					ans2 = i;
					break;
				}
			}
			else
			{
				s2 += y[i];
				if(s2+(10-i)/2<s1 || s1+(10-i)/2 < s2)
				{
					ans2 = i;
					break;
				}
			}
		}
		
		printf("%d\n",ans1<ans2?ans1:ans2);
	}
}