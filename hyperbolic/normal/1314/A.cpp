#include <stdio.h>
#include <algorithm>
#include <queue>

struct str{
	int x0;
	int y0;
}x[200010];
bool operator<(str a, str b)
{
	if(a.x0==b.x0) return a.y0>b.y0;
	return a.x0<b.x0;
}

std::priority_queue<int> Q;
int y[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].x0);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].y0);
	std::sort(x+1,x+a+1);
	
	long long int ans = 0;
	long long int C = 0;
	for(int i=1;i<=a;i++) y[i] = y[i-1]+1>x[i].x0?y[i-1]+1:x[i].x0;
	
	int s;
	int t = 1;
	for(int i=1;i<=a;i++)
	{
		if(Q.empty()) s = x[t].x0;
		
		while(t<=a)
		{
			if(x[t].x0==s)
			{
				Q.push(x[t].y0), C += x[t].y0;
				t++;
			}
			else break;
		}
		int k = Q.top();
		Q.pop();
		C-=k;
		s++;
		ans += C;		
	}
	
	printf("%lld",ans);
}