#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 1000000000
#define MIN -1000000000

std::priority_queue<int> Q2;
std::priority_queue<int, std::vector<int>, std::greater<int> > Q1;
void insert(int k)
{
	Q1.push(k);
	while(!Q1.empty()&&!Q2.empty()&&Q1.top()<Q2.top())
	{
		Q2.push(Q1.top());
		Q1.pop();
	}
	if(Q1.size()>Q2.size()+2)
	{
		Q2.push(Q1.top());
		Q1.pop();
	}
	if(Q2.size()>=Q1.size())
	{
		Q1.push(Q2.top());;
		Q2.pop();
	}
	if(Q1.size()>Q2.size()+2)
	{
		Q2.push(Q1.top());
		Q1.pop();
	}
}

int x[200010],y[400010];
std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		y[1] = x[1];
		M[y[1]] = 1;
		for(int i=2;i<=a;i++)
		{
			if(x[i-1]<x[i])
			{
				if(M[x[i]]==1)
				{
					y[2*i-2] = MAX;
					y[2*i-1] = MAX;
				}
				else
				{
					y[2*i-2] = MAX;
					y[2*i-1] = x[i];
				}
				M[x[i]] = 1;
			}
			else if(x[i-1]>x[i])
			{
				if(M[x[i]]==1)
				{
					y[2*i-2] = MIN;
					y[2*i-1] = MIN;
				}
				else
				{
					y[2*i-2] = MIN;
					y[2*i-1] = x[i];
				}
				M[x[i]] = 1;
			}
			else
			{
				y[2*i-2] = MAX;
				y[2*i-1] = MIN;
			}
		}
		
		while(!Q1.empty()) Q1.pop();
		while(!Q2.empty()) Q2.pop();
		// Q2<Q1
		insert(y[1]);
		for(int i=2;i<=a;i++)
		{
			insert(y[2*i-2]);
			insert(y[2*i-1]);
			if(Q1.top()!=x[i])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}