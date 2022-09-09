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

const int maxn = 100005;

int a[maxn];
int n, t;

int main()
{
	scanf("%d%d", &n, &t);
	t--;
	for (int i = 0; i < n - 1; i++) scanf("%d", &a[i]);
	int cur = 0;
	while (cur != t && cur < n - 1)
	{
		cur = cur + a[cur];
	}
	if (cur == t) printf("YES\n");
	else printf("NO\n");
	return 0;
}