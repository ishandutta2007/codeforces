#include <stdio.h>
#include <string.h>
#include <queue>
struct str{
	int x0;
	int y0;
	int z0;
};
bool operator<(str a, str b)
{
	return 2*a.x0+a.y0+a.z0 < 2*b.x0+b.y0+b.z0;
}
std::priority_queue<str> Q;
char x[2000010],y[2000010];
int A[2000010],ans[2000010],ans2[2000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x);
		int a = strlen(x);
		for(int i=0;i<a;i++)
		{
			y[2*i] = '-';
			y[2*i+1] = x[i];
		}
		y[2*a] = '-';
		
		int r = 0, p = 0;
		for(int i=0;i<=2*a;i++) A[i] = 0;
		for(int i=0;i<=2*a;i++)
		{
			if(i<=r) A[i] = A[2*p-i]<r-i?A[2*p-i]:r-i;
			else A[i] = 0;
			
			while(i-A[i]-1>=0 && i+A[i]+1 <= 2*a && y[i - A[i] - 1] == y[i + A[i] + 1]) A[i]++;
			if(r<i+A[i])
			{
				r = i+A[i];
				p = i;
			}
		}
		//for(int i=0;i<=2*a;i++) printf("%d",A[i]);
		//printf("\n");
		for(int i=0;i<a;i++) ans[i] = 0,ans2[i] = 0;
		for(int i=0;i<=a;i++) ans[(i/2)-(A[i]/2)] = ans[(i/2)-(A[i]/2)] > A[i]? ans[(i/2)-(A[i]/2)] : A[i];
		for(int i=a;i<=2*a;i++) ans2[(i/2)-(A[i]/2)+A[i]-1] = ans2[(i/2)-(A[i]/2)+A[i]-1] > A[i]? ans2[(i/2)-(A[i]/2)+A[i]-1] : A[i];
		
		p = ans[0];
		for(int i=0;i<a;i++)
		{
			p-=2;
			if(ans[i]<p) ans[i] = p;
			else p = ans[i];
		}
		
		p = ans2[a-1];
		for(int i=a-1;i>=0;i--)
		{
			p-=2;
			if(ans2[i]<p) ans2[i] = p;
			else p = ans2[i];
		}
		
		while(!Q.empty()) Q.pop();
		
		Q.push({0,ans[0],0});
		Q.push({0,0,ans2[a-1]});
		for(int i=0;i<a;i++)
		{
			if(i>=a-1-i) break;
			if(x[i]!=x[a-1-i]) break;
			Q.push({i+1,ans[i+1],0});
			Q.push({i+1,0,ans2[a-2-i]});
		}
		str A = Q.top();
		for(int i=0;i<A.x0;i++) printf("%c",x[i]);
		for(int i=A.x0;i<A.x0+A.y0;i++) printf("%c",x[i]);
		for(int i=a-A.x0-A.z0;i<=a-A.x0-1;i++) printf("%c",x[i]);
		for(int i=a-A.x0;i<=a-1;i++) printf("%c",x[i]);
		printf("\n");
	}
}