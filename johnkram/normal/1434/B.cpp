#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 600005
bool b[MAXN];
int n,m,N,i,j,ans[MAXN],a[MAXN];
set<int> s;
char c[10];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n<<1;i++)
	{
		scanf("%s",c);
		if(c[0]=='+')a[i]=0;
		else scanf("%d",a+i);
	}
	N=n;
	for(i=n<<1;i;i--)if(!a[i])
	{
		if(s.empty())
		{
			puts("NO");
			return 0;
		}
		ans[N--]=*s.begin();
		s.erase(s.begin());
	}
	else
	{
		if(b[a[i]]||!s.empty()&&*s.begin()<a[i])
		{
			puts("NO");
			return 0;
		}
		b[a[i]]=1;
		s.insert(a[i]);
	}
	puts("YES");
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}