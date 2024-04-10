#include <stdio.h>
#include <vector>
std::vector<int> V;
int count[200010],x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		V.push_back(x[1]);
		for(int i=2;i<=a;i++) if(x[i]!=x[i-1]) V.push_back(x[i]);
		for(int i=0;i<V.size();i++) count[V[i]]++;
		int min = a;
		for(int i=1;i<=a;i++)
		{
			if(count[i]>0)
			{
				int t = count[i]+1;
				if(i==V[0]) t--;
				if(i==V.back()) t--;
				min = min<t?min:t;
			}
		}
		printf("%d\n",min);
	}
}