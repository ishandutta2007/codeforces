#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll m,c[MAXN];
multiset<ll> s;
int n,i,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=1;i<=n;i++)
	{
		s.insert(a[i]+m);
		c[i]=c[i-1]+a[i];
		while(!s.empty()&&*s.begin()<=m+b[i])
		{
			c[i]-=(*s.begin())-m;
			s.erase(s.begin());
		}
		m+=b[i];
		c[i]-=(ll)b[i]*s.size();
		printf("%I64d ",c[i-1]+a[i]-c[i]);
	}
	return 0;
}