#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b%2==1) V1.push_back(b);
			else V2.push_back(b);
		}
		
		if(V1.size()==0)
		{
			printf("%d\n",a*(a-1)/2);
			continue;
		}
		
		int ans = 0;
		for(int i=0;i<V2.size();i++) ans += (a-i-1);
		for(int i=0;i<V1.size();i++)
		{
			for(int j=i+1;j<V1.size();j++)
			{
				if(gcd(V1[i],V1[j])>1) ans++;
			}
		}
		printf("%d\n",ans);
	}
}