#include <stdio.h>
#include <vector>
int query(int s, int t)
{
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int V[1010][1010];
int size[1010],check[1010];
int a;

void func(int k, int prev)
{
	check[k] = 1;
	for(int i=1;i<=a;i++)
	{
		if(i==prev) continue;
		if(V[k][i]==1) func(i,k);
	}
}

int func2(int k, int prev, int target)
{
	if(k==target) return 1;
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		if(i==prev) continue;
		if(V[k][i]==1) s += func2(i,k,target);
	}
	return s;
}

std::vector<int> V2;

int main()
{
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b][c] = 1;
		V[c][b] = 1;
	}
	func(1,0);
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) size[i] += V[i][j];
	for(int i=1;i<=a;i++) if(size[i]==1) V2.push_back(i);
	
	int ans = V2[0];
	
	while(1)
	{
		if(V2.size()<=1) break;
		int k = query(V2[0],V2[1]);
		ans = k;
		size[k] -= 2;

		
		for(int i=1;i<=a;i++)
		{
			if(V[k][i] == 1)
			{
				if(func2(i,k,V2[0])==1)
				{
					V[k][i] = 0;
					V[i][k] = 0;
					break;
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(V[k][i] == 1)
			{
				if(func2(i,k,V2[1])==1)
				{
					V[k][i] = 0;
					V[i][k] = 0;
					break;
				}
			}
		}
		
		for(int i=1;i<=a;i++) check[i] = 0;
		func(k,0);
		V2.clear();
		for(int i=1;i<=a;i++) if(check[i]==1 && size[i]==1) V2.push_back(i);
	}
	printf("! %d",ans);
	fflush(stdout);
}