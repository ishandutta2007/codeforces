#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
struct node
{
	int a,b;
	bool operator<(const node& y)const
	{
		return a<y.a;
	}
}a[MAXN],b[MAXN];
int n,m,i,j;
ll ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
	scanf("%d",&m);
	for(i=1;i<=m;i++)scanf("%d%d",&b[i].a,&b[i].b);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(i=j=1;i<=n&&j<=m;)if(a[i].a<b[j].a)ans+=a[i++].b;
	else if(a[i].a>b[j].a)ans+=b[j++].b;
	else ans+=max(a[i++].b,b[j++].b);
	for(;i<=n;i++)ans+=a[i].b;
	for(;j<=m;j++)ans+=b[j].b;
	cout<<ans<<endl;
	return 0;
}