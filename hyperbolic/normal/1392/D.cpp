#include <stdio.h>
#define MAX 12345678
int check[200010][5][5];
char x[200010];
int diff(char a, char b)
{
	return a==b?0:1;
}

int a;
int func(int s, int t, int last)
{
	if(s==a+1)
	{
		if((t==1&&last==1)||(t==1&&last==2)) return MAX;
		if((t==4&&last==3)||(t==4&&last==4)) return MAX;
		if((t==1&&last==1)||(t==3&&last==1)) return MAX;
		if((t==2&&last==4)||(t==4&&last==4)) return MAX;
		return 0;
	}
	
	if(check[s][t][last]!=-1) return check[s][t][last];
	
	if(t==1) return check[s][t][last] = func(s+1,2,last) + diff(x[s],'L');
	else if(t==4) return check[s][t][last] = func(s+1,3,last) + diff(x[s],'R');
	else if(t==2)
	{
		int s1 = func(s+1,3,last) + diff(x[s],'R');
		int s2 = func(s+1,4,last) + diff(x[s],'L');
		return check[s][t][last] = s1<s2?s1:s2;
	}
	else if(t==3)
	{
		int s1 = func(s+1,1,last) + diff(x[s],'R');
		int s2 = func(s+1,2,last) + diff(x[s],'L');
		return check[s][t][last] = s1<s2?s1:s2;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a+1;i++) for(int j=1;j<=4;j++) for(int k=1;k<=4;k++) check[i][j][k] = -1;
		
		
		int s1 = func(3,1,1) + diff('R',x[1]) + diff('R',x[2]);
		int s2 = func(3,2,2) + diff('R',x[1]) + diff('L',x[2]);
		int s3 = func(3,3,3) + diff('L',x[1]) + diff('R',x[2]);
		int s4 = func(3,4,4) + diff('L',x[1]) + diff('L',x[2]);
		
		int min = s1;
		min = min<s2?min:s2;
		min = min<s3?min:s3;
		min = min<s4?min:s4;
		printf("%d\n",min);
	}
}