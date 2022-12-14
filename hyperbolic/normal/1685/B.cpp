#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<int> V1,V2;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%s",x+1);
		int e = strlen(x+1);
		
		int count1 = 0, count2 = 0;
		for(int i=1;i<=e;i++)
		{
			if(x[i]=='A') count1++;
			else count2++;
		}
		if(count1!=a+c+d || count2!=b+c+d)
		{
			printf("NO\n");
			continue;
		}
		
		x[e+1] = x[e];
		int start = 1;
		int C = 0;
		for(int i=2;i<=e+1;i++)
		{
			if(x[i-1]==x[i])
			{
				int end = i-1;
				int n = end-start+1;
				if(n%2==0)
				{
					if(x[start]=='A') V1.push_back(n/2);
					else V2.push_back(n/2);
				}
				else C+= (n-1)/2;
				start = i;
			}
		}
		
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		for(int i=0;i<V1.size();i++)
		{
			int k = V1[i]<c?V1[i]:c;
			c -= k;
			V1[i] -= k;
			if(V1[i]>0) C += (V1[i]-1);
		}
		for(int i=0;i<V2.size();i++)
		{
			int k = V2[i]<d?V2[i]:d;
			d -= k;
			V2[i] -= k;
			if(V2[i]>0) C += (V2[i]-1);
		}
		
		
		if(c+d <= C) printf("YES\n");
		else printf("NO\n");
	}
}