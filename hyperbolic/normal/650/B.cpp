#include <stdio.h>
#include <string.h>
char x[1000010];
int check[1000010];
int main()
{
	int a,b,c,d,e,f,i,j,max,s;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%s",x+1);
	for(i=a+1;i<=2*a;i++) x[i] = x[i-a];
	for(i=2;i<=2*a;i++)
	{
		if(x[i]=='h') check[i]=1;
		else check[i] = c+1;
	}
	if(check[a+1]>d)
	{
		printf("0");
		return 0;
	}
	
	s=1,f=d-check[a+1];
	for(i=a+2;i<=2*a;i++)
	{
		if(f>=check[i]+b) f-=(check[i]+b) , s++;
		else break;
	}
	max = s;
	
	s=1,f=d-check[a+1];
	for(i=a;i>=2;i--)
	{
		if(f>=check[i]+b) f-=(check[i]+b) , s++;
		else break;
	}
	max = max>s?max:s;
	
	
	s=1,f=d-check[a+1];
	for(i=a+2;i<=2*a;i++)
	{
		if(f>=check[i]+2*b) f-=(check[i]+2*b),s++;
		else break;
	}
	for(i--,j=a;i>=a+1;i--)
	{
		for(;j>i-a;j--)
		{
			if(f>=check[j]+b) f-=(check[j]+b),s++;
			else break;
		}
		max = max>s?max:s;
		f += 2*b + check[i];
		s--;
	}
	
	s=1,f=d-check[a+1];
	for(i=a;i>=2;i--)
	{
		if(f>=check[i]+2*b) f-=(check[i]+2*b),s++;
		else break;
	}
	for(i++,j=a+2;i<=a+1;i++)
	{
		for(;j<i+a;j++)
		{
			if(f>=check[j]+b) f-=(check[j]+b),s++;
			else break;
		}
		max = max>s?max:s;
		f += 2*b + check[i];
		s--;
	}
	printf("%d",max);
}