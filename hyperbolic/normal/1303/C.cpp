#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V,ans;

int check[30],z[30],y[30][30];
void func(int k)
{
	check[k] = 1;
	ans.push_back(k);
	for(int i=1;i<=26;i++) if(y[k][i]==1 && check[i]==0) func(i);
}

char x[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		V.clear();
		
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=26;i++) for(int j=1;j<=26;j++) y[i][j] = 0;
		for(int i=1;i<=26;i++) check[i] = z[i] = 0;
		
		for(int i=1;i<a;i++)
		{
			y[x[i]-'a'+1][x[i+1]-'a'+1] = 1;
			y[x[i+1]-'a'+1][x[i]-'a'+1] = 1;
		}
		for(int i=1;i<=26;i++)
		{
			int s = 0;
			for(int j=1;j<=26;j++) s += y[i][j];
			z[i] = s;
			
			if(s>=3)
			{
				printf("NO\n");
				goto u;
			}
			if(s==1) V.push_back(i);
		}
		
		for(int i=0;i<V.size();i++)
		{
			if(check[V[i]]==0) func(V[i]);
		}
		for(int i=1;i<=26;i++)
		{
			if(check[i]==0)
			{
				if(z[i]!=0)
				{
					printf("NO\n");
					goto u;
				}
				else ans.push_back(i);
			}
		}
		printf("YES\n");
		for(int i=0;i<ans.size();i++) printf("%c",ans[i]+'a'-1);
		printf("\n");
		
		u:;
	}
}