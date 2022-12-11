#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXK=2005;

int ans[MAXK*MAXK];

int main()
{
	LL p;
	int k;
	scanf("%lld%d",&p,&k);
	bool ok=false;
	for (int i=0;i<MAXK*MAXK;i++)
	{
		ans[i]=(p%k+k)%k;
		p=(ans[i]-p)/k;
		if (ans[i])
			ok=true;
		if (ok&&p==0)
		{
			printf("%d\n",i+1);
			for (int j=0;j<=i;j++)
				printf("%d ",ans[j]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}