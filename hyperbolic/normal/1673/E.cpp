#include <stdio.h>

int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	
	int a = s, b = t, c = s-t;
	int ans = 0;
	while(a)
	{
		a/=2;
		ans += a;
	}
	while(b)
	{
		b/=2;
		ans -= b;
	}
	while(c)
	{
		c/=2;
		ans -= c;
	}
	if(ans>=1) return 0;
	else return 1;
}

int a,b;
int check2[31][1100010];
int func(int s, int t)
{
	if(s==0&&t==0) return 1;
	else if(t==0) return 0;
	else if(check2[a-s][t]!=0) return check2[a-s][t]-1;
	check2[a-s][t] = comb(s-1,t-1) + 1;
	return check2[a-s][t] - 1;
}

int check[1100010],x[1100010],y[1100010],ans[1100010];
int main()
{
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]<20) y[i] = (1<<x[i]);
		else y[i] = (1<<20);
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=20;j++)
		{
			if((i+j)<=a)
			{
				long long int s = x[i];
				int control = 0;
				for(int k=1;k<=j;k++)
				{
					s *= y[i+k];
					if(s>=(1<<20))
					{
						control = 1;
						break;
					}
				}
				if(control) continue;
				
				int s2 = (a-1) - (j+2);
				int t = b-2;
				if(i==1) s2++, t++;
				if(i+j==a) s2++, t++;
				if(s2<0) continue;
				if(s2<t) continue;
				if(t<0) t = 0;
				ans[s] += func(s2,t), ans[s] %= 2;
			}
		}
	}
	
	int start = (1<<20)-1;
	for(int i=start;i>=0;i--)
	{
		if(ans[i]==0) start = i-1;
		else break;
	}
	if(start==-1) printf("0");
	else for(int i=start;i>=0;i--) printf("%d",ans[i]);
}