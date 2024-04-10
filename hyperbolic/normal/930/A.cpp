#include <stdio.h>
#include <vector>

int x[100010];
int count[100010];
std::vector<int> V[100010];
void func(int k, int h)
{
	count[h]++;
	for(int i=0;i<V[k].size();i++) func(V[k][i],h+1);
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		x[i] = b;
		V[b].push_back(i);
	}
	func(1,1);
	
	int ans = 0;
	for(int i=1;i<=a;i++) ans += (count[i]%2);
	printf("%d",ans);
}