#include <stdio.h>

char x[200010];
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	
	int C1=0,C2=0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='(') C1++;
		if(x[i]==')') C2++;
	}
	if(C1!=C2)
	{
		printf("No");
		return 0;
	}
	
	
	int control = 0;
	int s1 = 0, s2 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='(') s1++;
		if(x[i]==')') s2++;
		if(s2>s1)
		{
			s2--;
			control++;
		}
	}
	if(control<=1) printf("Yes");
	else printf("No");
}