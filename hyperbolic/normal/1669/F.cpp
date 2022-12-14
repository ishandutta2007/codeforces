#include <stdio.h>
#include <map>

std::map<int,int> M;
int x[200010],s1[200010],s2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		s2[a+1] = x[a+1] = 0;
		for(int i=1;i<=a;i++) s1[i] = s1[i-1] + x[i];
		for(int i=a;i>=1;i--) s2[i] = s2[i+1] + x[i];
		
		for(int i=1;i<=a-1;i++) M[s1[i]] = i;
		
		int ans = 0;
		for(int i=a;i>=1;i--)
		{
			if(M.find(s2[i])!=M.end())
			{
				int t = M[s2[i]];
				ans = ans>t+(a-i+1)?ans:t+(a-i+1);
			}
			M.erase(s1[i-1]);
		}
		printf("%d\n",ans);
	}
}