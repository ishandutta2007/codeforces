#include <stdio.h>

char x[1010],y[1010];
int a,b;
int check[1010][30][30][3];
int control = 0;
int ans[1010];

void func(int k, int p1, int p2, int type)
{
	if(control) return;
	if(k>a)
	{
		if(type==1) return;
		for(int i=1;i<=a;i++) printf("%c",ans[i]+'a'-1);
		control = 1;
		return;
	}
	
	if(check[k][p1][p2][type]) return;
	check[k][p1][p2][type] = 1;
	
	if(type==1)
	{
		ans[k] = x[k];
		func(k+1,p2,x[k],1);
		if(control) return;
		for(int i=x[k]+1;i<=b;i++)
		{
			if(i==p1) continue;
			if(i==p2) continue;
			ans[k] = i;
			func(k+1,p2,i,0);
			if(control) return;
		}
	}
	else
	{
		for(int i=1;i<=b;i++)
		{
			if(i==p1) continue;
			if(i==p2) continue;
			ans[k] = i;
			func(k+1,p2,i,0);
			if(control) return;
		}
	}
}


int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) x[i] -= ('a'-1);
	
	if(a==1)
	{
		if(x[1]==b) printf("NO");
		else printf("%c",x[1]+'a');
		return 0;
	}
	
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==j) continue;
			if(b*i+j<b*x[1]+x[2]) continue;
			ans[1] = i;
			ans[2] = j;
			if(b*i+j==b*x[1]+x[2]) func(3,i,j,1);
			else func(3,i,j,0);
			if(control) return 0;
		}
	}
	printf("NO");
}