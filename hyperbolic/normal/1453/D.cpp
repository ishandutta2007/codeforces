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
		if(a%2==1)
		{
			printf("-1\n");
			continue;
		}
		a/=2;
		
		long long int s = 1;
		for(int i=1;i<60;i++) s*=2, s++;
		for(int i=59;i>=0;i--)
		{
			while(a>=s)
			{
				V.push_back(i);
				a-=s;
			}
			s/=2;
		}
		
		int ans = V.size()-1;
		for(int i=0;i<V.size();i++) ans += V[i];
		printf("%d\n",ans+1);
		
		printf("1 ");
		for(int i=0;i<V.size();i++)
		{
			for(int j=1;j<=V[i];j++) printf("0 ");
			if(i+1!=V.size())printf("1 ");
		}
		printf("\n");
	}
}