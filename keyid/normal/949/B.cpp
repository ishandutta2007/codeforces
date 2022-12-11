#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

LL query(LL x,LL len,LL st)
{
	if ((x+st)%2==1)
		return (st+x+1)/2;
	return query((x+st%2)/2,(len+st%2)/2,st+len);
}

int main()
{
	LL n;
	int q;
	scanf("%lld%d",&n,&q);
	while (q--)
	{
		LL x;
		scanf("%lld",&x);
		printf("%lld\n",query(x,n,0));
	}
	return 0;
}