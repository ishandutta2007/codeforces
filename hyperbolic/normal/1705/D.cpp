#include <stdio.h>
#include <vector>

int abs(int k)
{
	return k>0?k:-k;
}

std::vector<int> V1,V2,W1,W2;
char x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		W1.clear();
		W2.clear();
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		if(x[1]!=y[1])
		{
			printf("-1\n");
			continue;
		}
		if(x[a]!=y[a])
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<a;i++)
		{
			if(x[i]==x[i+1]) V1.push_back(0);
			else V1.push_back(1);
		}
		for(int i=1;i<a;i++)
		{
			if(y[i]==y[i+1]) V2.push_back(0);
			else V2.push_back(1);
		}
		
		for(int i=0;i<V1.size();i++) if(V1[i]==0) W1.push_back(i);
		for(int i=0;i<V2.size();i++) if(V2[i]==0) W2.push_back(i);
		
		if(W1.size()!=W2.size()) printf("-1\n");
		else
		{
			long long int ans = 0;
			for(int i=0;i<W1.size();i++) ans += abs(W1[i]-W2[i]);
			printf("%lld\n",ans);
		}
	}
}