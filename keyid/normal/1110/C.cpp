#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;
typedef pair <int,int> pii;

const int ans[24]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

void solve()
{
	int a;
	scanf("%d",&a);
	int b=0;
	for (int i=0;i<25&&a>=(1<<i);i++)
		if ((a>>i&1)==0)
			b|=1<<i;
	if (b)
		printf("%d\n",a+b);
	else
		printf("%d\n",ans[30-__builtin_clz(a)]);
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}