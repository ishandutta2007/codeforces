#include <stdio.h>
#define MIN -(long long int)1e16
int a;
int x[5010];

long long int check[5010][10];
int check2[5010][10];
int next[5010][10];
int sign[3]={1,-1};
long long int func(int s, int t)
{
	if(t==4) return MIN;
	if(s>a) return 0;
	if(check2[s][t]) return check[s][t];
	
	long long int s1 = func(s+1,t) + sign[t%2]*x[s];
	long long int s2 = func(s,t+1);
	if(s1>s2)
	{
		next[s][t] = 1;
		check2[s][t] = 1;
		return check[s][t] = s1;
	}
	else
	{
		next[s][t] = 2;
		check2[s][t] = 1;
		return check[s][t] = s2;
	}
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(1,0);
	
	int s = 1, t = 0;
	while(s<=a)
	{
		if(next[s][t]==1) s++;
		else
		{
			printf("%d ",s-1);
			t++;
		}
	}
	for(int i=t;i<=2;i++) printf("%d ",a);
}