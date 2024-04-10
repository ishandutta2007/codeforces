#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int n,a[MAXN];
LL sum[MAXN];

struct ret
{
	int p,pos;
	LL q;

	bool operator < (const ret &b) const
	{
		return b.p*(q-(LL)a[pos]*p)<p*(b.q-(LL)a[b.pos]*b.p);
	}
};

inline LL getsum(int len,int pos)
{
	return sum[pos]-sum[pos-len-1]+sum[n]-sum[n-len];
}

inline bool check(int len,int x)
{
	return getsum(len,x)*(2*len-1)>getsum(len-1,x)*(2*len+1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ret ans={0,0,-1LL};
	for (int i=1;i<=n;i++)
	{
		int l=1,r=min(i-1,n-i);
		while (l<=r)
		{
			int m=l+r>>1;
			if (check(m,i)) l=m+1;
			else r=m-1;
		}
		ans=max(ans,(ret){2*r+1,i,getsum(r,i)});
	}
	printf("%d\n",ans.p);
	printf("%d",a[ans.pos]);
	int l=(ans.p^1)>>1;
	for (int i=1;i<=l;i++) printf(" %d",a[ans.pos-i]);
	for (int i=0;i<l;i++) printf(" %d",a[n-i]);
	return 0;
}