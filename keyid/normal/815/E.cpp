#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map <LL,LL> f;

LL cal(LL n,LL d)
{
	if ((n+1)/2<d)
		return 0;
	if (f.find(n)!=f.end())
		return f[n];
	return f[n]=1+cal((n-1)/2,d)+cal(n-1-(n-1)/2,d);
}

LL cal2(LL n,LL d)
{
	if ((n+1)/2<d)
		return 0;
	if (f.find(n)!=f.end())
		return f[n];
	if ((n+1)/2==d)
		f[n]=1;
	return f[n]+=cal2((n-1)/2,d)+cal2(n-1-(n-1)/2,d);
}

LL solve(LL n,LL d,LL k)
{
	LL p=(n+1)/2;
	if (f[p-1]>=k)
		return solve(p-1,d,k);
	k-=f[p-1];
	if (p==d&&--k==0)
		return p;
	return p+solve(n-p,d,k);
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	LL n,k;
	scanf("%lld%lld",&n,&k);
	if (k==1)
		printf("1");
	else if (k==2)
		printf("%lld",n);
	else
	{
		k-=2;
		LL l=1,r=(n-1)/2;
		while (l<=r)
		{
			LL m=l+r>>1;
			f.clear();
			if (cal(n-2,m)>=k)
				l=m+1;
			else
				r=m-1;
		}
		f.clear();
		k-=cal(n-2,l);
		f.clear();
		cal2(n-2,r);
		printf("%lld\n",1+solve(n-2,r,k));
	}
	return 0;
}