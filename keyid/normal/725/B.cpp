#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	LL n;
	char s;
	scanf("%lld%c",&n,&s);
	LL ans=(n-1)/4*16;
	if (n%2==0)
		ans+=7;
	if (s>='d') ans+='f'-s+1;
	else ans+=s-'a'+4;
	printf("%lld",ans);
	return 0;
}