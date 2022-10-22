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
#define maxn 300005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

ll n,cnt,mx[maxn];
struct node{ll s,e,id;}p[maxn];
bool flag;

inline bool cmp(node x,node y)
{
	if(x.s==y.s) return x.e>y.e;
	return x.s<y.s;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].s>>p[i].e,p[i].id=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) mx[i]=max(mx[i-1],p[i].e);
	for(int i=1;i<=n;i++)
	{
		if(p[i].e<=mx[i-1])
		{
			flag=1;
			cout<<p[i].id<<" ";
			for(int j=1;j<i;j++)
				if(p[j].e==mx[i-1])
				{
					cout<<p[j].id;
					break;
				}
			break;
		}
	}
	if(flag==0) printf("-1 -1");
	return 0;
}