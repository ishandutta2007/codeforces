#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

bool go(ll b,ll a)
{
// 	cout << "go " << b << ' ' << a << endl;
	if (a==0) return false;
	bool res=go(a,b%a);
	if (!res) return true;
	b=b/a;
	if ((b%(a+1))%2==0) return true;
	return false;
}

int main()
{
	int NT;
	cin >> NT;
	for (int T=0;T<NT;T++)
	{
		ll a,b;
		cin >> a >> b;
		if (b<a) swap(a,b);
		if (go(b,a))
		{
			cout << "First" << endl;
		} else
		{
			cout << "Second" << endl;
		}
	}
	return 0;
}