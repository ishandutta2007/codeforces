#include <stdio.h>
#include <map>

std::map<long long int,int> M[12];
char x[70010][20];
int check[70010];
int size[70010];
long long int ans[70010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		for(int j=1;j<=9;j++) x[i][j]-='0';
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=9;j++)
		{
			long long int s = 0;
			for(int k=j;k<=9;k++)
			{
				s*=10;
				s+=x[i][k];
				if(M[k-j+1].find(s)==M[k-j+1].end()) M[k-j+1][s] = i;
				else if(M[k-j+1][s]!=i) M[k-j+1][s] = -1;
			}
		}
	}
	
	std::map<long long int,int> ::iterator it;
	for(int i=1;i<=9;i++)
	{
		for(it = M[i].begin();it!=M[i].end();it++)
		{
			if(it->second==-1) continue;
			if(check[it->second]==0)
			{
				check[it->second] = 1;
				ans[it->second] = it->first;
				size[it->second] = i;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		long long int t = ans[i];
		//printf("%lld %d!!\n",ans[i],size[i]);
		int s = 0;
		while(t)
		{
			s++;
			t/=10;
		}
		for(int j=1;j<=size[i]-s;j++) printf("0");
		if(ans[i]==0) printf("\n");
		else printf("%I64d\n",ans[i]);
	}
}