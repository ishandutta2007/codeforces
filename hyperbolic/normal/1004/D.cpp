#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int check[1000010];
int sum[1000010],a;
void func2(int s, int t)
{
	if(s>t)
	{
		int k = s;
		s = t;
		t = k;
	}
	for(int i=1;i<=s-1;i++) sum[i] += i;
	for(int i=s;i<=t;i++) sum[i] += s;
	for(int i=t+1;i<=t+s-1;i++) sum[i] += (t+s-i);
}
void clear()
{
	for(int i=1;i<=a;i++) sum[i] = 0;
}
int min = 0, max = 0;
int func(int s, int t)
{
	if(s<=2*min) return 0;
	if(t<=2*min) return 0;
	
	int X[10]={};
	int Y[10]={};
	X[1] = min+1;
	Y[1] = (max+2-X[1]);
	X[2] = s-min;
	Y[2] = (max+2-X[2]);
	Y[3] = min+1;
	X[3] = (max+2-Y[3]);
	Y[4] = t-min;
	X[4] = (max+2-Y[4]);
	
	for(int i=1;i<=4;i++)
	{
		int x1 = X[i];
		int y1 = Y[i];
		if(1<=x1&&x1<=s)
		{
			if(1<=y1&&y1<=t)
			{
				clear();
				func2(x1,y1-1);
				func2(x1-1,t-y1+1);
				func2(s-x1+1,t-y1);
				func2(s-x1,y1);
				for(int i=1;i<=a;i++) if(check[i]!=sum[i]) goto u;
		
				printf("%d %d\n",s,t);
				printf("%d %d",x1,y1);
				return 1;
				u:;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		check[b]++;
		max = max>b?max:b;
	}
	if(check[0]!=1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]!=4*i)
		{
			min = i-1;
			break;
		}
	}
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			int s = func(i,a/i);
			if(s==1) return 0;
		}
	}
	printf("-1");
}