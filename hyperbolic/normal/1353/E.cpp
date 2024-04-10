#include <stdio.h>
#include <vector>

char x[1000010];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		int count = 0;
		for(int i=1;i<=a;i++) if(x[i]=='1') count++;
		
		int ans = a;
		for(int i=1;i<=b;i++)
		{
			int count2 = 0;
			for(int j=i;j<=a;j+=b) if(x[j]=='1') count2++;
			V.clear();
			for(int j=i;j<=a;j+=b)
			{
				if(x[j]=='1') V.push_back(-1);
				else V.push_back(1);
			}
			
			int C = 0;
			int S = 0;
			for(int j=0;j<V.size();j++)
			{
				S = S+V[j]<V[j]?S+V[j]:V[j];
				C = C<S?C:S;
			}
			ans = ans<count+C?ans:count+C;
		}
		printf("%d\n",ans);
	}
}