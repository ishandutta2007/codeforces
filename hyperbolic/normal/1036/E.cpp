#include <stdio.h>
#include <set>

struct str{
	int x0;
	int y0;
	int z0;
	int w0;
}x[1010];

long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int min(long long int a, long long int b)
{
	return a<b?a:b;
}
long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}

std::set< std::pair<long long int, long long int> > T;

int func(int s, int t)
{
	long long int x1 = x[s].x0, y1 = x[s].y0, x2 = x[s].z0, y2 = x[s].w0;
	long long int x3 = x[t].x0, y3 = x[t].y0, x4 = x[t].z0, y4 = x[t].w0;
	long long int A = (y2-y1)*(x4-x3)-(y4-y3)*(x2-x1);
	long long int B = (y3-y1)*(x2-x1)*(x4-x3)-x3*(y4-y3)*(x2-x1)+x1*(y2-y1)*(x4-x3);
	
	long long int x0,y0;
	if(A==0) return 0;
	
	if(abs(B)%abs(A)==0) x0 = B/A;
	else return 0;
	
	if(x2!=x1)
	{
		long long int C = (y2-y1)*(x0-x1);
		if(abs(C)%abs(x2-x1)==0)
		{
			y0 = y1 + C/(x2-x1);
			if(min(x1,x2)<=x0&&x0<=max(x1,x2));
			else return 0;
			if(min(x3,x4)<=x0&&x0<=max(x3,x4));
			else return 0;
			if(min(y1,y2)<=y0&&y0<=max(y1,y2));
			else return 0;
			if(min(y3,y4)<=y0&&y0<=max(y3,y4));
			else return 0;
			
			T.insert(std::make_pair(x0,y0));
		}
		return 0;
	}
	else
	{
		long long int C = (y4-y3)*(x0-x3);
		if(abs(C)%abs(x4-x3)==0)
		{
			y0 = y3 + C/(x4-x3);
			if(min(x1,x2)<=x0&&x0<=max(x1,x2));
			else return 0;
			if(min(x3,x4)<=x0&&x0<=max(x3,x4));
			else return 0;
			if(min(y1,y2)<=y0&&y0<=max(y1,y2));
			else return 0;
			if(min(y3,y4)<=y0&&y0<=max(y3,y4));
			else return 0;
			
			T.insert(std::make_pair(x0,y0));
		}
		return 0;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		x[i] = {b,c,d,e};
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		T.clear();
		long long int S = gcd(abs(x[i].x0-x[i].z0),abs(x[i].y0-x[i].w0))+1;
		
		for(int j=1;j<=i-1;j++) func(i,j);
		ans += S-T.size();
	}
	printf("%lld",ans);
}