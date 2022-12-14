#include <stdio.h>

long long int func(long long int s, long long int t, long long int left)
{
	if(s>left&&t>left) return (left+1)*(left+2)/2;
	else if(s>left)
	{
		//left + ... + left-t
		return (left+1)*(t+1) -t*(t+1)/2;
	}
	else if(t>left)
	{
		return (left+1)*(s+1) - s*(s+1)/2;
	}
	else
	{
		if(t+s<=left) return (t+1)*(s+1);
		else
		{
			long long int k = s+t-left;
			return (t+1)*(s+1) - k*(k+1)/2;
		}
	}
}
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int max = a>b?a>c?a:c:b>c?b:c;
	long long int ans = 0;
	for(int i=max;i<=max+d;i++)
	{
		int left = d-(i-a);
		if(left>=0)
		{
			ans += func(i-b,i-c,left);
			int left2 = i-b-c;
			if(left2>=0) ans -= func(i-b,i-c,left2<left?left2:left);
		}
		left = d-(i-b);
		if(left>=0)
		{
			ans += func(i-a,i-c,left);
			int left2 = i-a-c;
			if(left2>=0) ans -= func(i-a,i-c,left2<left?left2:left);
		}
		left = d-(i-c);
		if(left>=0)
		{
			ans += func(i-a,i-b,left);
			int left2 = i-a-b;
			if(left2>=0) ans -= func(i-a,i-b,left2<left?left2:left);
		}
		left = d - (i-a) - (i-b);
		if(left>=0) ans -= func(i-c,0,left);
		left = d - (i-a) - (i-c);
		if(left>=0) ans -= func(i-b,0,left);
		left = d - (i-b) - (i-c);
		if(left>=0) ans -= func(i-a,0,left);
		left = d- (i-a) - (i-b) - (i-c);
		if(left>=0) ans += func(0,0,left);
		//printf("%d : %lld!!\n",i,ans);
	}
	printf("%lld",ans);
}