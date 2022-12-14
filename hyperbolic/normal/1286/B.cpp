#include <stdio.h>
#include <vector>
int control = 0;
std::vector<int> V[2010];
int check[20010],ans[2010];
int a;
int value[2010],parent[2010],size[2010];

int getSize(int k)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++) ans += getSize(V[k][i]);
	return ans;
	
}
void func(int k)
{
	if(control) return;
	if(value[k]>=getSize(k))
	{
		control = 1;
		return;
	}
	
	int p = 0;
	for(int i=1;i<=10*a;i++)
	{
		if(check[i]==0)
		{
			if(p==value[k])
			{
				check[i] = 1;
				ans[k] = i;
				goto u;
			}
			p++;
		}
	}
	
	u:;
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(i);
		parent[i] = b;
		value[i] = c;
	}
	
	int root = V[0][0];
	func(root);
	
	if(control) printf("NO");
	else
	{
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
	}
}