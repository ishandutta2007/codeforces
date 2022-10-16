#include <cstdio>
#include <algorithm>

using ll = long long;
ll a,b,n;
int T;

int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld%lld", &a, &b, &n);
		if(b<a) std::swap(a,b);
		int f=0;
		while(b<=n)
		{
			a+=b;
			std::swap(a,b);
			++f;
		}
		printf("%d\n", f);
	}
	return 0;
}