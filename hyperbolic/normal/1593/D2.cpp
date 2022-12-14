#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int b,ans,C;
//std::vector<int> V[2000010];
std::map<int,int> M,count;
void func(int k)
{
	/*for(int i=0;i<V[k].size();i++)
	{
		M[V[k][i]]++;
		if(M[V[k][i]]+C>=b) ans = ans>V[k][i]?ans:V[k][i];
	}*/
	
	for(int i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			M[i]++;
			if(i*i!=k) M[k/i]++;
			if(M[i]+C>=b) ans = ans>i?ans:i;
			if(M[k/i]+C>=b) ans = ans>k/i?ans:k/i;
		}
	}
}

int x[110];
int main()
{
	//for(int i=1;i<=2000000;i++) for(int j=i;j<=2000000;j+=i) V[j].push_back(i);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		b = a/2 - 1;
		ans = 1;
		
		for(int i=1;i<=a;i++) count[x[i]]++;
		
		for(std::map<int,int> ::iterator it = count.begin();it!=count.end();it++)
		{
			if((it->second)>=a/2)
			{
				printf("-1\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			M.clear();
			C = 0;
			for(int j=i+1;j<=a;j++)
			{
				if(x[j]==x[i]) C++;
				else func(x[j]-x[i]);
			}
		}
		printf("%d\n",ans);
		u:;
	}
}