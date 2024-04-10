#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
struct str{
	int x0;
	int y0;
}x[100010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0>b.y0;
	return a.x0<b.x0;
}
std::priority_queue<int> Q;
std::stack<int> St,St2;
int main()
{
	int a,b,i,s,ans=0,count,sum=0;
	scanf("%d",&a);
	for(i=1;i<=a;i++) scanf("%d",&x[i].x0);
	for(i=1;i<=a;i++) scanf("%d",&x[i].y0);
	for(i=1;i<=a;i++) sum+=x[i].y0;
	std::sort(x+1,x+a+1,cmp);
	for(i=1;i<=a;i++)
	{
		if(x[i].x0!=x[i-1].x0)
		{
			while(!St.empty()) Q.push(St.top()) , St.pop();
			while(!St2.empty()) Q.push(St2.top()) , St2.pop();
			count = 1;
			s = x[i].y0;
			St.push(x[i].y0);
			ans = ans>s?ans:s;
		}
		else
		{
			count++;
			if(!Q.empty()) St2.push(Q.top()), b = Q.top() , Q.pop();
			else b = 0;
			s+=b;
			s+=x[i].y0;
			St.push(x[i].y0);
			ans = ans>s?ans:s;
		}
	}
	printf("%d",sum-ans);
}