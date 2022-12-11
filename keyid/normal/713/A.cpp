#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map <LL,int> ms;

inline LL trans(LL x)
{
	LL ret=0,p=1;
	while (x)
	{
		if (x&1) ret+=p;
		p*=10;
		x/=10;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	char op[5];
	LL x;
	while (T--)
	{
		scanf("%s%lld",op,&x);
		x=trans(x);
		if (op[0]=='+') ms[x]++;
		else if (op[0]=='-') ms[x]--;
		else printf("%d\n",ms[x]);
	}
	return 0;
}