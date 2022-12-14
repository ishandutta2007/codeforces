#include <stdio.h>
#include <map>

char x[200010];
int y[200010];
std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		a*=2;
		scanf("%s",x+1);
		x[0] = x[a+1] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='(') y[i] = y[i-1]+1;
			else y[i] = y[i-1]-1;
		}
		
		int ans = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==')'&&x[i-1]==')') ans += M[y[i]];
			if(x[i]=='('&&x[i+1]=='(') M[y[i-1]] = 1;
		}
		printf("%d\n",ans);
	}
}