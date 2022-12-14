#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

std::vector<char> x[300010],y[300010];
char temp[300010];
int a,b;
int func1()
{
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int s1 = 0;
		for(int j=1;j<=b;j++) if(y[i][j]!=x[i][j]) s1++;
		int s2 = 0;
		for(int j=1;j<=b;j++) if(y[i][j-1]!=x[i][j]) s2++;
		ans += (s1<s2?s1:s2);
	}
	return ans;
}
int func2()
{
	int ans = 0;
	for(int j=1;j<=b;j++)
	{
		int s1 = 0;
		for(int i=1;i<=a;i++) if(y[i][j]!=x[i][j]) s1++;
		int s2 = 0;
		for(int i=1;i<=a;i++) if(y[i-1][j]!=x[i][j]) s2++;
		ans += (s1<s2?s1:s2);
	}
	return ans;
}

char p[10],P[10],type;
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",temp+1);
		x[i].push_back(0);
		for(int j=1;j<=b;j++) x[i].push_back(temp[j]);
		x[i].push_back(0);
	}
	for(int j=0;j<=b+1;j++) x[0].push_back(0);
	for(int j=0;j<=b+1;j++) x[a+1].push_back(0);
	
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) y[i].push_back(0);
	
	int ans = 123456789;
	p[1] = 'A', p[2] = 'G', p[3] = 'C', p[4] = 'T';
	do{
		for(int i=0;i<=a+1;i+=2) for(int j=0;j<=b+1;j+=2) y[i][j] = p[1];
		for(int i=0;i<=a+1;i+=2) for(int j=1;j<=b+1;j+=2) y[i][j] = p[2];
		for(int i=1;i<=a+1;i+=2) for(int j=0;j<=b+1;j+=2) y[i][j] = p[3];
		for(int i=1;i<=a+1;i+=2) for(int j=1;j<=b+1;j+=2) y[i][j] = p[4];
		
		int s = func1();
		int t = func2();
		if(ans>s)
		{
			ans = s;
			for(int i=1;i<=4;i++) P[i] = p[i];
			type = 1;
		}
		if(ans>t)
		{
			ans = t;
			for(int i=1;i<=4;i++) P[i] = p[i];
			type = 2;
		}
	}while(std::next_permutation(p+1,p+5));
	
	for(int i=0;i<=a+1;i+=2) for(int j=0;j<=b+1;j+=2) y[i][j] = P[1];
	for(int i=0;i<=a+1;i+=2) for(int j=1;j<=b+1;j+=2) y[i][j] = P[2];
	for(int i=1;i<=a+1;i+=2) for(int j=0;j<=b+1;j+=2) y[i][j] = P[3];
	for(int i=1;i<=a+1;i+=2) for(int j=1;j<=b+1;j+=2) y[i][j] = P[4];
	if(type==1)
	{
		for(int i=1;i<=a;i++)
		{
			int s1 = 0;
			for(int j=1;j<=b;j++) if(y[i][j]!=x[i][j]) s1++;
			int s2 = 0;
			for(int j=1;j<=b;j++) if(y[i][j-1]!=x[i][j]) s2++;
			
			if(s1<=s2) for(int j=1;j<=b;j++) x[i][j] = y[i][j];
			else for(int j=1;j<=b;j++) x[i][j] = y[i][j-1];
		}
	}
	else
	{
		for(int j=1;j<=b;j++)
		{
			int s1 = 0;
			for(int i=1;i<=a;i++) if(y[i][j]!=x[i][j]) s1++;
			int s2 = 0;
			for(int i=1;i<=a;i++) if(y[i-1][j]!=x[i][j]) s2++;
			
			if(s1<=s2) for(int i=1;i<=a;i++) x[i][j] = y[i][j];
			else for(int i=1;i<=a;i++) x[i][j] = y[i-1][j];
		}
	}
	
	//printf("%d??\n",ans);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) printf("%c",x[i][j]);
		printf("\n");
	}
}