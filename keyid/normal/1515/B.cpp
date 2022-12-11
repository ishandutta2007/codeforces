#include <bits/stdc++.h>
using namespace std;

bool is_sqr(int n)
{
	int m=sqrt(n+0.5);
	while (m*m>n) m--;
	while ((m+1)*(m+1)<n) m++;
	return m*m==n;
}

bool solve()
{
	int n;
	scanf("%d",&n);
	if (n&1)
		return false;
	n/=2;
	return is_sqr(n)||(n%2==0&&is_sqr(n/2));
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--)
		puts(solve()?"YES":"NO");
	return 0;
}