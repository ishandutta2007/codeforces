#include <stdio.h>

int check[10];
int check2[110];
void func(int s, int t, int k)
{
	if(s>0)
	{
		if(check2[k]==0) check2[k] = s;
		else check2[k] = check2[k]<s?check2[k]:s;
	}
	if(t>8) return;
	
	for(int i=1;i<=9;i++)
	{
		if(check[i]==0)
		{
			check[i] = 1;
			func(10*s+i,t+1,k+i);
			check[i] = 0;
		}
	}
}
int main()
{
	func(0,1,0);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a>45) printf("-1\n");
		else if(a==45) printf("123456789\n");
		else
		{
			if(check2[a]==0) printf("-1\n");
			else printf("%d\n",check2[a]);
		}
	}
}