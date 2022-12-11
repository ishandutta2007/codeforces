#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

bool solve()
{
	LL p,q,b;
	scanf("%lld%lld%lld",&p,&q,&b);
	LL g=__gcd(p,q);
	q/=g;
	while (q!=1)
	{
		g=__gcd(q,b);
		if (g==1)
			return false;
		while (q%g==0)
			q/=g;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	while (n--) puts(solve()?"Finite":"Infinite");
	return 0;
}