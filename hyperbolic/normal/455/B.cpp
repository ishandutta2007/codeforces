#include <stdio.h>
#include <string.h>

int next[200010][30];
int C = 1;

int func1(int k)
{
	int ans = 0;
	for(int i=0;i<26;i++)
	{
		if(next[k][i]!=0&&func1(next[k][i])==0) ans = 1;
	}
	return ans;
}

int func2(int k)
{
	int control = 0;
	for(int i=0;i<26;i++)
	{
		if(next[k][i]!=0)
		{
			control = 1;
			int t = func2(next[k][i]);
			if(t==1) return 0;
		}
	}
	if(control==0) return 0;
	return 1;
}

char x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int c = strlen(x+1);
		
		int state = 0;
		for(int j=1;j<=c;j++)
		{
			if(next[state][x[j]-'a']==0) next[state][x[j]-'a'] = C++;
			state = next[state][x[j]-'a'];
		}
	}
	
	int s1 = func1(0);
	int s2 = func2(0);
	
	if(s1==0) printf("Second");
	else
	{
		if(s2==1) printf("%s",b%2==1?"First":"Second");
		else printf("First");
	}	
}