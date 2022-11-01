#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,a[200005],lst,d,ans;
set<long long> s;
map<long long,long long> mp;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&d);d++;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]--;
		s.insert(a[i]);
	}
	lst=0;
	for (i=1;i<=n;i++)
	{
		set<long long>::iterator it=s.lower_bound(lst%m);
		if (it==s.end())
		{
			it=s.begin();
			lst=lst/m*m+m+*it;
		}
		else
		{
			lst=lst/m*m+*it;
		}
		mp[*it]=lst/m+1;
		if (i<n)
		{
			if (lst%m+d>=m)
			{
				lst=lst/m*m+m;
			}
			else lst+=d;
		}
		s.erase(*it);
	}
	printf("%I64d\n",lst/m+1);
	for (i=1;i<=n;i++)
	{
		printf("%I64d ",mp[a[i]]);
	}
	return 0;
}