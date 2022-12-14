#include <stdio.h>
#include <vector>
#include <algorithm>
struct str{
	int x0;
	int y0;
	int z0;
	int index;
}x[100010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0)
	{
		if(a.y0==b.y0) return a.z0<b.z0;
		return a.y0<b.y0;
	}
	return a.x0<b.x0;
}

int func(int L, int R)
{
	std::vector<int> V;
	int p = L;
	while(1)
	{
		if(p>R) break;
		if(p==R)
		{
			V.push_back(x[p].index);
			break;
		}
		if(x[p].y0==x[p+1].y0)
		{
			printf("%d %d\n",x[p].index,x[p+1].index);
			p+=2;
		}
		else
		{
			V.push_back(x[p].index);
			p++;
		}
	}
	for(int i=0;i+1<V.size();i+=2) printf("%d %d\n",V[i],V[i+1]);
	if(V.size()%2==1) return V[V.size()-1];
	else return -1;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		x[i] = {b,c,d,i};
	}
	std::sort(x+1,x+a+1,cmp);
	
	std::vector<int> V;
	int L = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i].x0!=x[L].x0)
		{
			int k = func(L,i-1);
			L = i;
			if(k!=-1) V.push_back(k);
		}
	}
	int k = func(L,a);
	if(k!=-1) V.push_back(k);
	for(int i=0;i<V.size();i+=2) printf("%d %d\n",V[i],V[i+1]);
}