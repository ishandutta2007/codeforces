#include <stdio.h>
#include <vector>
#include <algorithm>

int next[150010];
int size[150010];
std::vector<int> V[150010];
void func(int k)
{
	printf("%d ",k);
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d,e;
		scanf("%d%d",&d,&e);
		
		b = d, c = e;
		while(next[b]!=0) b = next[b];
		while(next[c]!=0) c = next[c];
		if(size[b]<=size[c])
		{
			while(next[e]!=0)
			{
				int f = e;
				e = next[e];
				next[f] = b;
			}
			next[c] = b;
			V[b].push_back(c);
			size[c] += size[b];
		}
		else
		{
			while(next[d]!=0)
			{
				int f = d;
				d = next[d];
				next[f] = c;
			}
			next[b] = c;
			V[c].push_back(b);
			size[b] += size[c];
		}
	}
	int b = 1;
	while(next[b]!=0) b = next[b];
	func(b);
}