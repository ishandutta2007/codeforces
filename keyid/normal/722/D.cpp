#include <bits/stdc++.h>
using namespace std;

const int MAXN=50005;

int n,a[MAXN];
set <int> s;

bool check(int x)
{
	s.clear();
	for (int i=0;i<n;i++)
	{
		int t=a[i];
		while (t>x||s.find(t)!=s.end()) t>>=1;
		if (t) s.insert(t);
		else return false;
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=1,r=1000000000;
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m)) r=m-1;
		else l=m+1;
	}
	check(l);
	for (set <int> :: iterator it=s.begin();it!=s.end();++it) printf("%d ",*it);
	return 0;
}