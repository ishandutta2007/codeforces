#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		ll a, b;
		scanf(LLD LLD, &a, &b);
		for (int i = 61; i >= 0; i--)
		{
			ll near = ((b + 1) / (1LL << (ll)i)) * (1LL << (ll)i) - 1;
			if (near >= a)
			{
				printf(LLD "\n", near);
				break;
			}
		}
	}
	return 0;
}