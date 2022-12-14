#include <stdio.h>
#include <algorithm>
#include <queue>

int C;
int sum[500010];
int get(int s, int t)
{
	int ans = 0;
	s+=C,t+=C;
	while(s<t)
	{
		if(s%2==1)
		{
			ans += sum[s];
			s++;
		}
		if(t%2==0)
		{
			ans += sum[t];
			t--;
		}
		s/=2,t/=2;
	}
	if(s==t) ans+=sum[t];
	return ans;
}
void update(int u)
{
	u+=C;
	while(u>0)
	{
		sum[u]++;
		u/=2;
	}
}
struct str{
	double x0;
	double y0;
}x[100010];

double abs(double k)
{
	return k>0?k:-k;
}
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0>b.y0;
	return a.x0<b.x0;
}

struct str2{
	double value;
	int index;
};
bool operator<(str2 a, str2 b)
{
	if(a.value==b.value) return a.index<b.index;
	return a.value>b.value;
}
std::priority_queue<str2> Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c<0)
		{
			x[i].x0 = (double)(-c)/(d-b);
			x[i].y0 = (double)(-c)/(d+b);
		}
		else
		{
			x[i].x0 = (double)(c)/(-d+b);
			x[i].y0 = (double)(c)/(-d-b);
		}
	}
	std::sort(x+1,x+a+1,cmp);
	for(int i=1;i<=a;i++)
	{
		str2 A;
		A.value = x[i].y0;
		A.index = i;
		Q.push(A);
	}
	long long int sum = 0;
	for(C=1;C<a;C*=2); C--;
	while(!Q.empty())
	{
		str2 A = Q.top();
		Q.pop();
		int x0 = A.index;
		sum += get(x0+1,a);
		update(x0);
	}
	printf("%I64d",sum);
}