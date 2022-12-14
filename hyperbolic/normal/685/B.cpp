#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
int son[300010];
int height[300010];
int up[300010];
int next[300010][25];
int makeSon(int k)
{
	int sum = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==up[k]) continue;
		sum += makeSon(V[k][i]);
	}
	return son[k] = sum+1;
}
void makeNext(int k)
{
	int c = 1;
	int t = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==up[k]) continue;
		if(c==1)
		{
			t = V[k][i];
			c = 0;
		}
		else
		{
			if(son[t]<son[V[k][i]]) t = V[k][i];
		}
	}
	next[k][0] = t;
}
int findNext(int k ,int t)
{
	int s = k;
	int count = 0;
	while(t)
	{
		if(t%2==1) s = next[s][count];
		t/=2;
		count++;
	}
	return s;
}
int solve(int T);
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	up[0] = 0;
	up[1] = 0;
	for(int i=2;i<=a;i++)
	{
		scanf("%d",&c);
		up[i] = c;
		V[c].push_back(i);
	}
	makeSon(1);
	for(int i=1;i<=a;i++) makeNext(i);
	for(int k=1;k<=20;k++)
	{
		for(int i=1;i<=a;i++) next[i][k] = next[next[i][k-1]][k-1];
	}
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		printf("%d\n",solve(c));
	}
}
int solve(int T)
{
	int s = T;
	int min = 1, max = 300010;
	int ans = T;
	for(int i=20;i>=0;i--)
	{
		//printf("%d\n",s);
		if(son[next[s][i]]*2>son[T])
		{
			ans = next[s][i];
			s = next[s][i];
		}
	}
	/*while(min<=max)
	{
		int h = (min+max)/2;
		if(findNext(T,h)==0)
		{
			max = h-1;
		}
		else
		{
			if(son[findNext(T,h)]*2>son[T])
			{
				ans = findNext(T,h);
				min = h+1;
			}
			else
			{
				max = h-1;
			}
		}
	}*/
	return ans;
}