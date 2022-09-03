#include<cstdio>

char s[4];

int main()
{
	int i,n,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		if(s[1]=='+')r++;
		else r--;
	}
	printf("%d",r);
}