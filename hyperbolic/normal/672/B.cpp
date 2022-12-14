#include <stdio.h>
char x[100010];
int check[30];
int main()
{
	int a,ans=0;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	if(a>26)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		check[x[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(check[i]==0) continue;
		else ans+=check[i]-1;
	}
	printf("%d",ans);
}