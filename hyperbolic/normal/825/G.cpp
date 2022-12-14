#include <stdio.h>
#include <vector>

std::vector<int> V[1000010];
int min[1000010];
void func(int k, int prev, int val)
{
	val = val<k?val:k;
	min[k] = val;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,val);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	int c,d;
	scanf("%d%d",&c,&d);
	d = (d)%a+1;
	func(d,0,a+1);
	int val2 = d;
	int last = 0;
	for(int i=1;i<b;i++)
	{
		scanf("%d%d",&c,&d);
		d = (d+last)%a+1;
		if(c==1) val2 = val2<min[d]?val2:min[d];
		else
		{
			int ans = min[d]<val2?min[d]:val2;
			printf("%d\n",ans);
			last = ans;
		}
	}
}