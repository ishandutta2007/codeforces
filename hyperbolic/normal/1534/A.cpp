#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;
char x[110][110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='R') V1.push_back((i+j)%2);
				if(x[i][j]=='W') V2.push_back((i+j)%2);
			}
		}
		for(int i=0;i<V1.size();i++)
		{
			if(V1[i]!=V1[0])
			{
				printf("NO\n");
				goto u;
			}
		}
		for(int i=0;i<V2.size();i++)
		{
			if(V2[i]!=V2[0])
			{
				printf("NO\n");
				goto u;
			}
		}
		
		if(V1.size()>0 && V2.size()>0 && V1[0]==V2[0])
		{
			printf("NO\n");
			continue;
		}
		
		int type1, type2;
		if(V1.size()>0 && V2.size()>0) type1 = V1[0], type2 = V2[0];
		else if(V1.size()>0) type1 = V1[0], type2 = 1-V1[0];
		else if(V2.size()>0) type1 = 1-V2[0], type2 = V2[0];
		else type1 = 0, type2 = 1;
		
		printf("YES\n");
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if((i+j)%2==type1) printf("R");
				else printf("W");
			}
			printf("\n");
		}
		
		u:;
	}
}