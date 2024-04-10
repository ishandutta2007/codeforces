#include <stdio.h>
#include <vector>

std::vector<int> V;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int L = 1, R = a;
		while(L<=R)
		{
			if(x[L]==x[R]) L++,R--;
			else
			{
				int n, control;
				V.clear();
				for(int i=L;i<=R;i++) if(x[i]!=x[L]) V.push_back(x[i]);
				n = V.size()-1;
				control = 1;
				for(int i=0;i<=n;i++) if(V[i]!=V[n-i]) control = 0;
				if(control==1)
				{
					printf("YES\n");
					goto u;
				}
				
				V.clear();
				for(int i=L;i<=R;i++) if(x[i]!=x[R]) V.push_back(x[i]);
				n = V.size()-1;
				control = 1;
				for(int i=0;i<=n;i++) if(V[i]!=V[n-i]) control = 0;
				if(control==1)
				{
					printf("YES\n");
					goto u;
				}
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}