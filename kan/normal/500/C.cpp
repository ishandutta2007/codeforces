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

const int maxn = 505;

int w[maxn];
int last[maxn];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);
	for (int i = 0; i < n; i++) last[i] = -1;
	ll answer = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		for (int j = 0; j < n; j++) if (last[j] > last[x]) answer += w[j];
		last[x] = i;
	}
	cout << answer << endl;
	return 0;
}