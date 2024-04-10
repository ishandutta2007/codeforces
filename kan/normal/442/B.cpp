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

const int maxn = 105;

int n;
ld p[maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	reverse(p, p + n);
	ld v0 = 1;
	ld v1 = 0;
	ld answer = 0;
	for (int i = 0; i < n; i++)
	{
		v1 = v0 * p[i] + v1 * (1 - p[i]);
		v0 = v0 * (1 - p[i]);
		answer = max(answer, v1);
	}
	cout.precision(20);
	cout << answer << endl;
	return 0;
}