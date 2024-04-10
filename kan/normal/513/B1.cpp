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

#define pb push_back
#define all(x) begin(x), end(x)

vector<int> front, back;

int main()
{
	int n;
	ll m;
	scanf("%d" LLD, &n, &m);
	m--;
	for (int i = 0; i < n - 1; i++)
	{
		if (m >= (1LL << (n - 2 - i)))
		{
			back.pb(i);
			m -= (1LL << (n - 2 - i));
		} else front.pb(i);
	}
	for (auto x : front) printf("%d ", x + 1);
	printf("%d", n - 1 + 1);
	for (int i = (int)back.size() - 1; i >= 0; i--) printf(" %d", back[i] + 1);
	printf("\n");
	return 0;
}