#include <stdio.h>
#include <vector>

char x[4010][4010];
std::vector<int> V[4010],S;
int check[4010],check2[4010];
int val3;
int func(int k, int col)
{
	if(check[k]!=0) return 0;
	check[k] = col;
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==val3) continue;
		ans += func(V[k][i],col);
	}
	return ans;
}

int y[4010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) V[i].clear();
		for(int i=0;i<=a+1;i++) check[i] = check2[i] = 0;
		for(int i=0;i<=a+1;i++) y[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]=='1')
				{
					V[i].push_back(j);
				}
			}
		}
		
		S.clear();
		val3 = -1;
		for(int i=1;i<=a;i++) if(check[i]==0) S.push_back(func(i,S.size()+1));
		if(S.size()==1)
		{
			printf("0\n");
			continue;
		}
		
		for(int j=0;j<=a;j++) check2[j] = check[j];
		for(int i=1;i<=a;i++)
		{
			V[i].clear();
			int size1 = S[check[i]-1];
			for(int j=1;j<=a;j++) if(check2[i]==check2[j] && x[i][j]=='0') V[i].push_back(j);
			for(int j=1;j<=a;j++) check[j] = 0;
			int size2 = func(i,-1);
			if(size1==size2)
			{
				printf("1\n%d\n",i);
				goto u;
			}
			V[i].clear();
			for(int j=1;j<=a;j++) if(check2[i]==check2[j] && x[i][j]=='1') V[i].push_back(j);
			for(int j=1;j<=a;j++) check[j] = check2[j];
		}
		
		if(S.size()==2)
		{
			int ans1 = 0;
			for(int i=0;i<S.size();i++) if(S[i]<S[ans1]) ans1 = i;
			printf("%d\n",S[ans1]);
			
			ans1++;
			for(int j=1;j<=a;j++) if(check2[j]==ans1) printf("%d ",j);
			printf("\n");
		}
		else
		{
			int ans1, ans2;
			for(int i=1;i<=a;i++) if(check2[i]==1) ans1 = i;
			for(int i=1;i<=a;i++) if(check2[i]==2) ans2 = i;
			printf("2\n");
			printf("%d %d\n",ans1,ans2);
		}
		u:;
	}
}