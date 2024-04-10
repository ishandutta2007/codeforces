#include <bits/stdc++.h>
using namespace std;

int n,i;
int lst[200005];
struct _
{
	int id,x;
};
_ a[100005];

bool cmp(_ x,_ y)
{
	return x.x>y.x;
}

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);a[i].x--;
		a[i].id=i;
	} 
	
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		int t=a[i].id;
		lst[i]=t*2-1;
		if (i!=n) printf("%d %d\n",t*2-1,a[i+1].id*2-1);
	}
	
	for (i=1;i<=n;i++)
	{
		int t=a[i].id;
		int p=lst[i+a[i].x];
		printf("%d %d\n",t*2,p);
		if(!lst[i+a[i].x+1]) lst[i+a[i].x+1]=t*2;
	}
	
	return 0;
}