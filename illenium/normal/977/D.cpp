#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 105
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

struct node{ll w,p;}a[maxn];
ll n;

inline bool cmp(node x,node y)
{
	if(x.p==y.p) return x.w<y.w;
	return x.p>y.p;
}

int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].w;
		ll tmp=a[i].w,tmp2=0;
		while(tmp%3==0&&tmp!=0)
		{
			tmp2++;
			tmp/=3;
		}
		a[i].p=tmp2;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].w<<" ";
	return 0;
}