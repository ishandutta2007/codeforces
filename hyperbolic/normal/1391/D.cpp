#include <stdio.h>
#include <vector>
#define MAX 123456789
int diff(int s, int t)
{
	int count = 0;
	if(s%2!=t%2) count++;
	s/=2, t/=2;
	
	if(s%2!=t%2) count++;
	s/=2, t/=2;
	
	if(s%2!=t%2) count++;
	s/=2, t/=2;
	
	return count;
}

int a,b;
int y[1000010];
char x[1000010];
std::vector<int> V[5];

int check[1000010][10];
int func1(int s, int t)
{
	if(s>b) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	int k = t;
	int p2 = k%2;
	k/=2;
	int p1 = k%2;
	
	int ans = MAX;
	for(int i=0;i<4;i++)
	{
		k = i;
		int q2 = k%2;
		k/=2;
		int q1 = k%2;
		if((p1+p2+q1+q2)%2==1)
		{
			int value = func1(s+1,i) + diff(y[s],i);
			ans = ans<value?ans:value;
		}
	}
	return check[s][t] = ans;
}

int func2(int s, int t)
{
	if(s>b) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	int k = t;
	int p3 = k%2;
	k/=2;
	int p2 = k%2;
	k/=2;
	int p1 = k%2;
	
	int ans = MAX;
	for(int i=0;i<8;i++)
	{
		k = i;
		int q3 = k%2;
		k/=2;
		int q2 = k%2;
		k/=2;
		int q1 = k%2;
		
		if((p1+p2+q1+q2)%2==1&&(p2+p3+q2+q3)%2==1)
		{
			int value = func2(s+1,i) + diff(y[s],i);
			ans = ans<value?ans:value;
		}
	}
	return check[s][t] = ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	if(a>=4&&b>=4)
	{
		printf("-1");
		return 0;
	}
	if(a==1||b==1)
	{
		printf("0");
		return 0;
	}
	
	if(a<=3)
	{
		for(int i=1;i<=a;i++) for(int j=0;j<=b;j++) V[i].push_back(0);
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			for(int j=1;j<=b;j++) V[i][j] = x[j]-'0';
		}
	}
	else
	{
		for(int i=1;i<=b;i++) for(int j=0;j<=a;j++) V[i].push_back(0);
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			for(int j=1;j<=b;j++) V[j][i] = x[j]-'0';
		}
		int t = a;
		a = b;
		b = t;
	}
	for(int j=1;j<=b;j++)
	{
		int s = 0;
		for(int i=1;i<=a;i++)
		{
			s*=2;
			s += V[i][j];
		}
		y[j] = s;
	}
	
	if(a==2)
	{
		for(int j=1;j<=b;j++) for(int i=0;i<4;i++) check[j][i] = -1;
		
		int ans = MAX;
		for(int i=0;i<4;i++)
		{
			int s = func1(2,i) + diff(y[1],i);
			ans = ans<s?ans:s;
		}
		if(ans>=MAX) printf("-1");
		else printf("%d",ans);
	}
	else
	{
		for(int j=1;j<=b;j++) for(int i=0;i<8;i++) check[j][i] = -1;
		int ans = MAX;
		for(int i=0;i<8;i++)
		{
			int s = func2(2,i) + diff(y[1],i);
			ans = ans<s?ans:s;
		}
		if(ans>=MAX) printf("-1");
		else printf("%d",ans);
	}
}