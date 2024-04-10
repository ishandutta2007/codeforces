#include <stdio.h>
#include <vector>
#include <string.h>

int abs(int k)
{
	return k>0?k:-k;
}
std::vector<int> V,V2,V3;
char x[110];
int y[110];
int count[110],count2[110],check[110];
int color[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++) count[i] = count2[i] = check[i] = color[i] = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) count2[x[i]-'a']++;
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		
		V.clear();
		for(int i=1;i<=b;i++) V.push_back(i);
		
		for(int p=1;!V.empty();p++)
		{
			V2.clear();
			V3.clear();
			
			for(int i=0;i<V.size();i++)
			{
				if(y[V[i]]==0) V2.push_back(V[i]);
				else V3.push_back(V[i]);
			}
			
			for(int j=0;j<V2.size();j++) check[V2[j]] = p;
			for(int i=0;i<V.size();i++)
			{
				if(y[V[i]]==0) continue;
				int C = 0;
				for(int j=0;j<V2.size();j++) C+= abs(V[i]-V2[j]);
				y[V[i]] -= C;
			}
			count[p] = V2.size();
			V = V3;
		}
		
		int p = 1;
		for(int i=25;i>=0;i--)
		{
			if(count[p]==0) break;
			if(count[p]<=count2[i])
			{
				color[p] = i;
				p++;
			}
		}
		for(int i=1;i<=b;i++) printf("%c",'a'+color[check[i]]);
		printf("\n");
	}
}