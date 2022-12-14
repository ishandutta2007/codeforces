#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		long long int a;
		scanf("%lld",&a);
		while(a)
		{
			V.push_back(a%10);
			a/=10;
		}
		
		int ans = 12345;
		for(int i=0;i<V.size();i++)
		{
			if(V[i]==0)
			{
				for(int j=i+1;j<V.size();j++)
				{
					if(V[j]==0||V[j]==5)
					{
						int p = i + (j-i-1);
						ans = ans<p?ans:p;
					}
				}
			}
			if(V[i]==5)
			{
				for(int j=i+1;j<V.size();j++)
				{
					if(V[j]==2||V[j]==7)
					{
						int p = i + (j-i-1);
						ans = ans<p?ans:p;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}