#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;

const int MAXN=200005;

char s[MAXN],a[2][MAXN];

bool solve()
{
	int n;
	scanf("%d%s",&n,s);
	int cnt0=0,cnt1;
	for (int i=0;i<n;i++)
		if (s[i]=='0')
			cnt0++;
	if (cnt0%2)
		return false;
	cnt1=n-cnt0;
	int sum[2]={0,0},c1=0,p0=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='1')
		{
			c1++;
			if (c1>cnt1/2)
			{
				a[0][i]=a[1][i]=')';
				sum[0]--;
				sum[1]--;
			}
			else
			{
				a[0][i]=a[1][i]='(';
				sum[0]++;
				sum[1]++;
			}
		}
		else
		{
			a[p0][i]='(';
			sum[p0]++;
			p0^=1;
			a[p0][i]=')';
			sum[p0]--;
		}
		if (sum[0]<0||sum[1]<0)
			return false;
	}
	puts("YES");
	a[0][n]=a[1][n]=0;
	puts(a[0]);
	puts(a[1]);
	return true;
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--)
		if (!solve())
			puts("NO");
	return 0;
}