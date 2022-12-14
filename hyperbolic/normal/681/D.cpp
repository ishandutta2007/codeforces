#include <stdio.h>
#include <vector>
int ans[1000010];
int x[100010];
int up[100010];
std::vector<int> V[100010];
int num=1,control=0;
void func(int k, int target)
{
	if(x[k]!=target)
	{
		ans[num] = k;
		num++;
		if(x[k]!=k) control = 1;
		else func(k,k);
	}
	else
	{
		for(int i=0;i<V[k].size();i++)
		{
			func(V[k][i],target);
		}
	}
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		//c d 
		V[c].push_back(d);
		up[d] = c;
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(up[i]==0)
		{
			ans[num] = i;
			num++;
			func(i,i);
		}
	}
	if(control) printf("-1");
	else
	{
		printf("%d\n",num-1);
		for(int i=num-1;i>=1;i--) printf("%d\n",ans[i]);
	}
}