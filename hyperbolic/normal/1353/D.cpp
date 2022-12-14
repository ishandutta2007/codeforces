#include <stdio.h>
#include <queue>
int ans[200010];
struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.second-a.first+1==b.second-b.first+1) return a.first>b.first;
	return a.second-a.first+1 < b.second-b.first+1;
}
std::priority_queue<str> Q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int C = 1;
		Q.push({1,a});
		while(!Q.empty())
		{
			str A = Q.top();
			Q.pop();
			int L = A.first;
			int R = A.second;
			if(L>R) continue;
			
			int h = (L+R)/2;
			ans[h] = C++;
			Q.push({L,h-1});
			Q.push({h+1,R});
		}
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}