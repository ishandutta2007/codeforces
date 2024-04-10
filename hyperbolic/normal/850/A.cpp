#include <stdio.h>
#include <vector>
struct str{
	int x1;
	int x2;
	int x3;
	int x4;
	int x5;
}V[1010];
str operator-(str a, str b)
{
	return {a.x1-b.x1,a.x2-b.x2,a.x3-b.x3,a.x4-b.x4,a.x5-b.x5};
}
int operator*(str a, str b)
{
	return a.x1*b.x1+a.x2*b.x2+a.x3*b.x3+a.x4*b.x4+a.x5*b.x5;
}

std::vector<int> ans;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e,f;
		scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
		V[i] = {b,c,d,e,f};
	}
	if(a>100)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(j==i) continue;
			for(int k=1;k<=a;k++)
			{
				if(k==i) continue;
				if(j==k) continue;
				
				str A = V[j] - V[i];
				str B = V[k] - V[i];
				if(A*B>0) goto u;
			}
		}
		ans.push_back(i);
		u:;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}