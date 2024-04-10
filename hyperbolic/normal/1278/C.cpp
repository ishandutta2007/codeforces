#include <stdio.h>
#include <map>
#define MAX 12345678

std::map<int,int> M;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=2*b;j++) scanf("%d",&x[j]);

		M.clear();
		int s = 0;
		int ans = 2*b;
		
		M[0] = b;	
		for(int j=1;j<=b;j++)
		{
			s += (x[j]==1?-1:1);
			M[s] = b-j;
		}
		
		s = 0;
		ans = ans<M[0]+b?ans:M[0]+b;
		for(int j=2*b;j>=b+1;j--)
		{
			s += (x[j]==1?1:-1);
			if(M.find(s)!=M.end())
			{
				int t = j-b-1;
				ans = ans<M[s]+t?ans:M[s]+t;
			}
		}
		printf("%d\n",ans);
	}
}