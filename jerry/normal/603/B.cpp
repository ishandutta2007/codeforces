#include <bits/stdc++.h>
using namespace std;

long long p, k, s, m=1e9+7;

long long f(long long a, long long b)
{
	if (b == 1) return a;
	long long t = f(a, b>>1);
	if (b&1) return t*t%m*a%m;
	return t*t%m;
}

int main()
{
	cin >> p >> k;
	if (k > 1)
	{
		for (long long x=k;x!=1;x=(x*k)%p) s++; s++;
		cout << f(p, (p-1)/s) << endl;
	} else if (k == 1) cout << f(p, p) << endl;
	else cout << f(p, p-1) << endl;
	return 0;
}