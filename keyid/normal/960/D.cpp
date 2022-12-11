#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

LL sh[100];

void query(int b,LL x)
{
	if (b<0)
		return;
	printf("%lld ",(x-sh[b]+(1LL<<b))%(1LL<<b)+(1LL<<b));
	query(b-1,x/2);
}

int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int op;
		LL X,K;
		scanf("%d%lld",&op,&X);
		if (op!=3)
			scanf("%lld",&K);
		if (op==1)
		{
			int b=63-__builtin_clzll(X);
			sh[b]=(sh[b]+K+(1LL<<b))%(1LL<<b);
		}
		else if (op==2)
		{
			int b=63-__builtin_clzll(X);
			K=(K+(1LL<<b))%(1LL<<b);
			for (int i=b;i<60;i++)
			{
				sh[i]=(sh[i]+K)%(1LL<<i);
				K*=2;
			}
		}
		else
		{
			int b=63-__builtin_clzll(X);
			printf("%lld ",X);
			X=(X+sh[b])%(1LL<<b)+(1LL<<b);
			query(b-1,X/2);
			puts("");
		}
	}
	return 0;
}