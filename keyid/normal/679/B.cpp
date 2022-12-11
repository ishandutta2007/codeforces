#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define sc second

typedef long long LL;
typedef pair <int,LL> pil;

inline int getk(LL x)
{
	int l=1,r=100000;
	while (l<=r)
	{
		LL m=l+r>>1;
		if (m*m*m>x) r=m-1;
		else l=m+1;
	}
	return r;
}

inline LL cb(int x)
{
	return (LL)x*x*x;
}

inline pil solve(LL m)
{
	if (!m) return mp(0,0);
	int k=getk(m);
	LL k3=cb(k);
	pil t1=solve(m-k3);
	t1.fi++;t1.sc+=k3;
	if (k==1) return t1;
	pil t2=solve(3LL*k*(k-1));
	t2.fi++;t2.sc+=cb(k-1);
	return max(t1,t2);
}

int main()
{
	LL m;
	scanf("%lld",&m);
	pil ans=solve(m);
	printf("%d %lld",ans.fi,ans.sc);
	return 0;
}