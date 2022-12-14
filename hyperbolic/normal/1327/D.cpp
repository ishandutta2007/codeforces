#include <stdio.h>
#include <vector>


int x[200010],y[200010];
int check[200010];
std::vector<int> V;
void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	V.push_back(y[k]);
	func(x[k]);
}

int func2()
{
	for(int i=1;i<=V.size();i++)
	{
		if(V.size()%i!=0) continue;
		for(int j=0;j<i;j++)
		{
			for(int k=j;k<V.size();k+=i) if(V[k]!=V[j]) goto u;
			
			return i;
			u:;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int ans = 12345678;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				V.clear();
				func(i);
				int s = func2();
				ans = ans<s?ans:s;
			}
		}
		printf("%d\n",ans);
	}
}