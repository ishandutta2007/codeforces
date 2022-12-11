#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int n,L,q[MAXN*2],s[MAXN*2];
LL a[MAXN*4],b[MAXN*2];

bool check(int dis)
{
	int s1=0,h1=0,s2=0,h2=0,qh=0,qt=-1;
	for (int i=0;i<n*2;i++)
	{
		while (h1<4*n&&a[h1]<=b[i]+dis)
		{
			h1++;
			s1++;
		}
		while (h2<4*n&&a[h2]<b[i]-dis)
		{
			h2++;
			s2++;
		}
		while (qh<=qt&&b[q[qh]]-dis<=b[i]+dis-L)
			qh++;
		s[i]=s2-i;
		while (qh<=qt&&s[q[qt]]<=s[i])
			qt--;
		q[++qt]=i;
		if (s1-i-s[q[qh]]<=0)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
		a[i+n]=a[i]+L;
		a[i+n*2]=a[i]+L*2;
		a[i+n*3]=a[i]+L*3LL;
	}
	for (int i=0;i<n;i++)
		scanf("%lld",&b[i]);
	sort(b,b+n);
	for (int i=0;i<n;i++)
	{
		b[i]+=L;
		b[i+n]=b[i]+L;
	}
	int l=0,r=(L-1)/2;
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m))
			r=m-1;
		else
			l=m+1;
	}
	printf("%d",l);
	return 0;
}