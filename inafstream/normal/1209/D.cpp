#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int fa[100005];
int n,k;

int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}

int main()
{
	int i,s=0;
	
	scanf("%d%d",&n,&k);
	rep(i,n)fa[i]=i;
	rep(i,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (fnd(x)==fnd(y))
		{
			s++;
		}
		else
		{
			fa[fnd(x)]=fnd(y);
		}
	}
	
	cout<<s<<endl;
	
	return 0;
}