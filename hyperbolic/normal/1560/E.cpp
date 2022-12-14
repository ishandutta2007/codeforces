#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

char x[1000010];
std::vector<char> V,V2;
int check[110],weight[110],check2[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		for(int i=0;i<26;i++) check[i] = weight[i] = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=a;i>=1;i--)
		{
			if(check[x[i]-'a']==0)
			{
				check[x[i]-'a'] = 1;
				V.push_back(x[i]);
			}
		}
		std::reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++) weight[V[i]-'a'] = (i+1);
		
		int sum = 0;
		int p = -1;
		for(int i=1;i<=a;i++)
		{
			sum += weight[x[i]-'a'];
			if(sum==a)
			{
				p = i;
				break;
			}
		}
		
		if(p==-1) printf("-1\n");
		else
		{
			V2.clear();
			for(int i=1;i<=p;i++) check2[i] = 0;
			for(int i=0;i<V.size();i++)
			{
				for(int j=1;j<=p;j++) if(check2[j]==0) V2.push_back(x[j]);
				for(int j=1;j<=p;j++) if(x[j]==V[i]) check2[j] = 1;
			}
			
			for(int i=1;i<=a;i++)
			{
				if(V2[i-1]!=x[i])
				{
					printf("-1\n");
					goto u;
				}
			}
			for(int i=1;i<=p;i++) printf("%c",x[i]);
			printf(" ");
			for(int i=0;i<V.size();i++) printf("%c",V[i]);
			printf("\n");
		}
		u:;
	}
}