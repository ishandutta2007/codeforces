#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 12345678
struct str{
	long long int x0;
	int index;
}x[100010];
int pivot = 0;
long long int m = 1;
bool cmp(str a, str b)
{
	long long int a0 = a.x0&m;
	long long int b0 = b.x0&m;
	return a0>b0;
}

std::vector<int> V[100010];
int check[100010],check2[100010];
std::stack<int> St,St2;
int func(int k ,int prev)
{
	if(check[k]==1)
	{
		int count = 0;
		while(!St.empty())
		{
			count++;
			int v = St.top();
			if(v==k) break;
			St2.push(v);
			St.pop();
		}
		while(!St2.empty()) St.push(St2.top()),St2.pop();
		return count;
	}
	
	int ans = MAX;
	check2[k] = 1;
	check[k] = 1;
	St.push(k);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int s = func(V[k][i],k);
		ans = ans<s?ans:s;
	}
	St.pop();
	check[k] = 0;
	return ans;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i].x0);
	for(int i=1;i<=a;i++) x[i].index = i;
	
	if(a<=2)
	{
		printf("-1");
		return 0;
	}
	
	for(pivot=0;pivot<=60;pivot++)
	{
		std::sort(x+1,x+a+1,cmp);
		if((x[3].x0&m)!=0)
		{
			printf("3");
			return 0;
		}
		else if((x[2].x0&m)!=0)
		{
			V[x[1].index].push_back(x[2].index);
			V[x[2].index].push_back(x[1].index);
		}
		m*=2;
	}
	
	int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		if(check2[i]==0)
		{
			int s = func(i,0);
			ans = ans<s?ans:s;
		}
	}
	if(ans>=MAX) printf("-1");
	else printf("%d",ans);
	
}