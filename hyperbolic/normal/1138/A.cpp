#include <stdio.h>
#include <vector>

int x[100010];
std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=x[i-1])
		{
			V.push_back(count);
			count = 1;
		}
		else count++;
	}
	V.push_back(count);
	int ans = 0;
	for(int i=0;i+1<V.size();i++)
	{
		int t = V[i]<V[i+1]?V[i]:V[i+1];
		ans = ans>t?ans:t;
	}
	printf("%d",2*ans);
}