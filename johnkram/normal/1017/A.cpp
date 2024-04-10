#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct node
{
	int a,b;
	bool operator<(const node& y)const
	{
		if(a==y.a)return b<y.b;
		return a>y.a;
	}
}e[MAXN];
int a,b,c,d,n,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e[i].a=a+b+c+d;
		e[i].b=i;
	}
	sort(e+1,e+n+1);
	for(i=1;i<=n;i++)if(e[i].b==1)cout<<i<<endl;
	return 0;
}