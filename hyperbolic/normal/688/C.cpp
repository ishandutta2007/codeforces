#include <stdio.h>
#include <vector>
#include <queue>
struct str{
	int x0;
	int y0;
};
std::queue<str> Q;
std::vector<int> V[100010];
int ans = 0;
int check[100010];
void func(int k)
{
	int count = 1;
	str A;
	A.x0 = k;
	A.y0 = 1;
	Q.push(A);
	while(!Q.empty())
	{
		str c = Q.front();
		Q.pop();
		if(check[c.x0]!=0) continue;
		if(c.y0%2==1) check[c.x0] = 1;
		else check[c.x0] = 2;
		for(int i=0;i<V[c.x0].size();i++)
		{
			if(check[V[c.x0][i]]==0)
			{
				str B;
				B.x0 = V[c.x0][i];
				B.y0 = c.y0+1;
				Q.push(B);
			}
			else if(check[V[c.x0][i]]+check[c.x0]==3);
			else ans = -1;
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
		V[c].push_back(d);
		V[d].push_back(c);	
	}
	for(int i=1;i<=a;i++) func(i);
	if(ans==-1)
	{
		printf("-1");
		return 0;
	}
	else
	{
		int s1=0,s2=0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1) s1++;
			else if(check[i]==2) s2++;
		}
		printf("%d\n",s1);
		for(int i=1;i<=a;i++) if(check[i]==1) printf("%d ",i);
		printf("\n%d\n",s2);
		for(int i=1;i<=a;i++) if(check[i]==2) printf("%d ",i);
	}
}