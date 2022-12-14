#include <stdio.h>

int count[1000010];
char x[10];
int main()
{
	int a;
	scanf("%d",&a);
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		count[b]++;
		if(count[b]==8) s4++;
		if(count[b]==6) s3++;
		if(count[b]==4) s2++;
		if(count[b]==2) s1++;
	}
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%s",x+1);
		scanf("%d",&c);
		if(x[1]=='+')
		{
			count[c]++;
			if(count[c]==8) s4++;
			if(count[c]==6) s3++;
			if(count[c]==4) s2++;
			if(count[c]==2) s1++;
		}
		else
		{
			count[c]--;
			if(count[c]==7) s4--;
			if(count[c]==5) s3--;
			if(count[c]==3) s2--;
			if(count[c]==1) s1--;
		}
		if(s2>=2 || (s2==1 && s1>=3) || (s2==1&&s1==2&&s3==1) || (s2==1&&s4>=1)) printf("YES\n");
		else printf("NO\n");
	}
}