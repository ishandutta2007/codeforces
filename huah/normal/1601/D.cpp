#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
#include<set>
#define ll long long
using namespace std;
const int inf = 0x7fffffff;
int n,d;
#define maxn 1000009
struct node{
	int s,a;
}a[maxn];
int cmp2(node a,node b)
{
	if(max(a.a,a.s)==max(b.a,b.s))
	{
		return a.s<b.s;
	}
	return max(a.s,a.a)<max(b.a,b.s); 
}
int f[maxn],val[maxn],cnt=0;
signed main()
{
	scanf("%d%d",&n,&d);
	
	int res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].s,&a[i].a);
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++)	
		if(d<=a[i].s)
			d=max(d,a[i].a),res++;
	printf("%d\n",res);
	return 0;
}