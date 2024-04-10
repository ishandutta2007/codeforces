#include <stdio.h>

int ans1[100010],ans2[100010];
char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int b = (a+1)/2;
	for(int i=b;i>=1;i--)
	{
		if(x[i]!='0')
		{
			for(int j=i-1;j>=1;j--) ans1[i-1-j] += (x[j]-'0');
			for(int j=a;j>=i;j--) ans1[a-j] += (x[j]-'0');
			break;
		}
	}
	for(int i=b+1;i<=a;i++)
	{
		if(x[i]!='0')
		{
			for(int j=i-1;j>=1;j--) ans2[i-1-j] += (x[j]-'0');
			for(int j=a;j>=i;j--) ans2[a-j] += (x[j]-'0');
			break;
		}
	}
	for(int i=0;i<=100000;i++) ans1[i+1]+=(ans1[i]/10),ans1[i]%=10;
	for(int i=0;i<=100000;i++) ans2[i+1]+=(ans2[i]/10),ans2[i]%=10;
	
	int s1=-1,s2=-1;
	for(int i=100001;i>=0;i--)
	{
		if(ans1[i]!=0)
		{
			s1 = i;
			break;
		}
	}
	for(int i=100001;i>=0;i--)
	{
		if(ans2[i]!=0)
		{
			s2 = i;
			break;
		}
	}
	/*for(int j=s1;j>=0;j--) printf("%d",ans1[j]);
	printf("!!\n");
	for(int j=s2;j>=0;j--) printf("%d",ans2[j]);
	printf("!!\n");*/
	if(s1==-1) for(int j=s2;j>=0;j--) printf("%d",ans2[j]);
	else if(s2==-1) for(int j=s1;j>=0;j--) printf("%d",ans1[j]);
	else
	{
		for(int i=100001;i>=0;i--)
		{
			if(ans1[i]<ans2[i])
			{
				for(int j=s1;j>=0;j--) printf("%d",ans1[j]);
				return 0;
			}
			if(ans1[i]>ans2[i])
			{
				for(int j=s2;j>=0;j--) printf("%d",ans2[j]);
				return 0;
			}
		}
		for(int j=s1;j>=0;j--) printf("%d",ans1[j]);
		return 0;
	}
}