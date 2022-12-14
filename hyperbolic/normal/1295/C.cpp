#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> V[30];
int func(int s, int t)
{
	// s-> V[t]
	if(V[t].empty()) return -1;
	int min = 0, max = V[t].size()-1;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[t][h]>s)
		{
			ans = V[t][h];
			max = h-1;
		}
		else min = h+1;
	}
	return ans;
}

int next[100010][30];
char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		int b = strlen(x+1), c = strlen(y+1);
		for(int i=0;i<=26;i++) V[i].clear();
		
		for(int i=1;i<=b;i++) V[x[i]-'a'].push_back(i);
		for(int i=1;i<=b;i++) for(int j=0;j<26;j++) next[i][j] = func(i,j);
		
		int pivot = -1;
		int count = 0;
		for(int i=1;i<=c;i++)
		{
			if(pivot!=-1)
			{
				if(next[pivot][y[i]-'a']==-1) pivot = -1;
				else pivot = next[pivot][y[i]-'a'];
			}
			if(pivot==-1)
			{
				if(V[y[i]-'a'].empty())
				{
					printf("-1\n");
					goto u;
				}
				else
				{
					pivot = V[y[i]-'a'][0];
					count++;
				}
			}
		}
		printf("%d\n",count);
		u:;
	}
}