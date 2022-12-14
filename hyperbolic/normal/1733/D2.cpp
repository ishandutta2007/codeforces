#include <stdio.h>
#include <vector>

#define MAX (long long int)1e16
int n;
long long int b,c;
long long int check[100010];
std::vector<int> index;

long long int func(int k)
{
	if(k>=n) return 0;
	if(check[k]!=MAX) return check[k];
	
	long long int s1 = func(k+1);
	long long int s2 = MAX;
	if(k+1<n) s2 = func(k+2) + (index[k+1]-index[k])*b - c;
	return check[k] = s1<s2?s1:s2;
}

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		int a;
		scanf("%d%lld%lld",&a,&b,&c);
		scanf("%s%s",x+1,y+1);
		
		for(int i=1;i<=a;i++) if(x[i]!=y[i]) index.push_back(i);
		if(index.size()%2==1)
		{
			printf("-1\n");
			continue;
		}
		n = index.size();
		
		b = b<2*c?b:2*c;
		
		if(b>=c)
		{
			if(index.size()==2)
			{
				if(index[0]+1==index[1]) printf("%lld\n",b);
				else printf("%lld\n",c);
				continue;
			}
			else printf("%lld\n",c*(index.size()/2));
		}
		else
		{
			for(int i=0;i<=n;i++) check[i] = MAX;
			long long int ans = c*(index.size()/2) + func(0);
			printf("%lld\n",ans);
		}
	}
}