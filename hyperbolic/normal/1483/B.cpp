#include <stdio.h>
#include <queue>
#include <vector>
 
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
 
std::queue<int> event;
int x[100010];
int prev[100010],next[100010],check[100010];
int save[100010];
std::vector<int> temp;
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		temp.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			check[i] = 1;
			next[i] = i+1;
			prev[i] = i-1;
		}
		next[a] = 1, prev[1] = a;
		
		for(int i=2;i<=a;i++) event.push(i);
		event.push(1);
		
		int p = -1;
		while(!event.empty())
		{
			int t = event.front();
			event.pop();
			if(gcd(x[prev[t]],x[t])!=1) continue;
			
			temp.push_back(t);
			check[t] = 0;
			next[prev[t]] = next[t];
			prev[next[t]] = prev[t];
			if(!event.empty() && event.front()==next[t]) event.pop();
			if(check[next[t]]!=0) event.push(next[t]);
		}
		
		printf("%d ",temp.size());
		for(int i=0;i<temp.size();i++) printf("%d ",temp[i]);
		printf("\n");
		
	}
}